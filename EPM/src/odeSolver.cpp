/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/*                      Early Plume Microphysics                    */
/*                              (EPM)                               */
/*                                                                  */
/* odeSolver Program File                                           */
/*                                                                  */
/* Author               : Thibaud M. Fritz                          */
/* Time                 : 1/10/2018                                 */
/* File                 : odeSolver.cpp                             */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "odeSolver.hpp"

namespace EPM
{
     
    template<class System> odeSolver<System>::odeSolver( System system_, Vector_1D &x_, bool adapt, bool stop_, RealDouble t ):
        system( system_ ),
        vars( x_ ),
        currentTime( 0.0 ),
        timeStep( 0.0 ),
        adaptive( adapt ),
        controlled_stepper(),
        stop( stop_ ),
        threshold( t )
    {

        /* Constructor */

    } /* End of odeSolver::odeSolver */

    template<class System> odeSolver<System>::~odeSolver()
    {

        /* Destructor */

    } /* End of odeSolver::~odeSolver */

    template<class System> odeSolver<System>::odeSolver( const odeSolver &solver )
    {

        /* Copy */

        system = solver.system;
        vars = solver.vars;
        currentTime = solver.currentTime;
        timeStep = solver.timeStep;

    } /* End of odeSolver::odeSolver */
    
    template<class System> odeSolver<System>& odeSolver<System>::operator=( const odeSolver &solver )
    {

        if ( &solver == this )
            return *this;

        system = solver.system;
        vars = solver.vars;
        currentTime = solver.currentTime;
        timeStep = solver.timeStep;
        return *this;

    } /* End of odeSolver::operator= */

    template<class System> void odeSolver<System>::updateTime( RealDouble t_ )
    {

        currentTime = t_;

    } /* End of odeSolver::updateTime */
    
    template<class System> void odeSolver<System>::updateStep( RealDouble dt_ )
    {

        timeStep = dt_;

    } /* End of odeSolver::updateStep */

    template<class System> UInt odeSolver<System>::integrate( RealDouble start_time, RealDouble end_time, RealDouble dt, streamingObserver observer )
    {

        unsigned int nStep;

        if ( end_time > start_time ) {
            if ( adaptive ) {
                if ( stop ) {
                //nStep = boost::numeric::odeint::integrate_adaptive( boost::numeric::odeint::make_controlled< error_stepper_type >( EPM_ATOLS, EPM_RTOLS ), system, vars, start_time, end_time, dt, observer );
                    nStep = boost::find_if( make_adaptive_range( boost::numeric::odeint::make_controlled< error_stepper_type>( EPM_ATOLS, EPM_RTOLS ), system, vars, start_time, end_time, dt, observer), done );
                }
            } else {
                nStep = boost::numeric::odeint::integrate( system, vars, start_time, end_time, dt, observer );
            }
        } else {
            std::cout << "\nIn odeSolver::integrate: end_time is smaller than start_time!";
            return 0;
        }

        if ( nStep >= 1 ) {
            updateTime( end_time );
        }

        return nStep;

    } /* End of odeSolver::integrate */
    
    template<class System> UInt odeSolver<System>::integrate( RealDouble start_time, RealDouble end_time, RealDouble dt )
    {

        unsigned int nStep;

        if ( end_time > start_time ) {
            if ( adaptive ) {
                nStep = boost::numeric::odeint::integrate_adaptive( controlled_stepper, system, vars, start_time, end_time, dt );
            } else {
                nStep = boost::numeric::odeint::integrate( system, vars, start_time, end_time, dt );
            }
        } else {
            std::cout << "\nIn odeSolver::integrate: end_time is smaller than start_time!";
            return 0;
        }
        
        if ( nStep >= 1 ) {
            updateTime( end_time );
        }

        return nStep;

    } /* End of odeSolver::integrate */
        
    template<class System> 
    void odeSolver<System>::updateThreshold( RealDouble t )
    {

        threshold = t;

    } /* End of odeSolver::updateThreshold */

        
    template<class System> 
    bool odeSolver<System>::done( const RealDouble &x )
    {

        return ( x <= threshold );

    } /* End of odeSolver::done */

    template<class System>
    Vector_1D odeSolver<System>::getState() const
    {

        return vars;

    } /* End of odeSolver::getState */

    streamingObserver::streamingObserver( Vector_2D &states, Vector_1D &times, const char* filename, UInt write_every ):
        m_write_every( write_every ),
        m_count( 0 ),
        fileName( filename ),
        m_states( states ),
        m_times( times )

    {

        /* Constructor */

    } /* End of streamingObserver::streamingObserver */

    streamingObserver::~streamingObserver( )
    {

        /* Destructor */

    } /* End of streamingObserver::~streamingObserver */

    streamingObserver& streamingObserver::operator=( const streamingObserver &obs )
    {

        if ( &obs == this )
            return *this;

        m_write_every = obs.m_write_every;
        m_count = obs.m_count;
        m_states = obs.m_states;
        m_times = obs.m_times;
        fileName = obs.fileName;
        return *this;

    } /* End of streamingObserver::operator= */

    void streamingObserver::operator()( const Vector_1D &x, double t )
    {

        if ( ( m_count % m_write_every ) == 0 ) {
         
            m_states.push_back( x );
            m_times.push_back( t );

            m_count++;

        }

    } /* End of streamingObserver::operator() */

    void streamingObserver::print2File( ) const
    {

        std::ofstream file (fileName);

        unsigned int iIndex, counter;

        if ( file.is_open() == 0 ) {

            std::cout << "\nIn streamingObserver::streamingObserver: Couldn't open " << fileName << "!\n";

        }
        else {

            file << " Time [s], ";
            for ( iIndex = 0; iIndex < m_states[0].size() - 1; iIndex++ ) {
                file << "x[" << iIndex << "], ";
            }
            iIndex = m_states[0].size() - 1;
            file << "x[" << iIndex;
            for ( counter = 0; counter < m_states.size(); counter++ ) {
                file << "\n " << m_times[counter] << ", ";
                for ( iIndex = 0; iIndex < m_states[counter].size() - 1; iIndex++ ) {
                    file << m_states[counter][iIndex] << ", ";
                }
                iIndex = m_states[counter].size() - 1;
                file << m_states[counter][iIndex];
            }

            file << "\n";
            file.close();

        }

    } /* End of streamingObserver::print2File */

    template class odeSolver<void ( const Vector_1D&, Vector_1D&, RealDouble )>;

}

/* End of odeSolver.cpp */
