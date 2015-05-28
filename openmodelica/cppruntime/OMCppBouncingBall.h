#pragma once
#if defined(__TRICORE__) || defined(__vxworks)
  #define BOOST_EXTENSION_SYSTEM_DECL
  #define BOOST_EXTENSION_EVENTHANDLING_DECL
#endif


#include "System/SystemDefaultImplementation.h"
/*includes removed for static linking not needed any more
#ifdef RUNTIME_STATIC_LINKING
  #include <boost/shared_ptr.hpp>
  #include <boost/weak_ptr.hpp>
  #include <boost/numeric/ublas/vector.hpp>
  #include <boost/numeric/ublas/matrix.hpp>
  #include <string>
  #include <vector>
  #include <map>

  using std::string;
  using std::vector;
  using std::map;

  #include <SimCoreFactory/Policies/FactoryConfig.h>
  #include <SimController/ISimController.h>
  #include <System/IMixedSystem.h>

  #include <boost/numeric/ublas/matrix_sparse.hpp>
  typedef uBlas::compressed_matrix<double, uBlas::column_major, 0, uBlas::unbounded_array<int>, uBlas::unbounded_array<double> > SparseMatrix;
#endif //RUNTIME_STATIC_LINKING
*/
//Forward declaration to speed-up the compilation process
class Functions;
class EventHandling;
class DiscreteEvents;

/*****************************************************************************
*
* Simulation code for BouncingBall generated by the OpenModelica Compiler.
* System class BouncingBall implements the Interface IMixedSystem
*
*****************************************************************************/

class BouncingBall: public IContinuous, public IEvent, public IStepEvent, public ITime, public ISystemProperties , public SystemDefaultImplementation
{
public:

    BouncingBall(IGlobalSettings* globalSettings, boost::shared_ptr<IAlgLoopSolverFactory> nonlinsolverfactor, boost::shared_ptr<ISimData> sim_data, boost::shared_ptr<ISimVars> sim_vars);
    BouncingBall(BouncingBall &instance);
    
    virtual ~BouncingBall();
    
    /// Releases the Modelica System
    virtual void destroy();
    /// Provide number (dimension) of variables according to the index
    virtual int getDimContinuousStates() const;
    /// Provide number (dimension) of boolean variables
    virtual int getDimBoolean() const;
    /// Provide number (dimension) of integer variables
    virtual int getDimInteger() const;
    /// Provide number (dimension) of real variables
    virtual int getDimReal() const ;
    /// Provide number (dimension) of string variables
    virtual int getDimString() const ;
    /// Provide number (dimension) of right hand sides (equations and/or residuals) according to the index
    virtual int getDimRHS()const;
    
    //Resets all time events
    
    // Provide variables with given index to the system
    virtual void getContinuousStates(double* z);
    virtual void getNominalStates(double* z);
    // Set variables with given index to the system
    virtual void setContinuousStates(const double* z);
    
    // Update transfer behavior of the system of equations according to command given by solver
    virtual bool evaluateAll(const UPDATETYPE command = IContinuous::UNDEF_UPDATE);
    virtual void evaluateODE(const UPDATETYPE command = IContinuous::UNDEF_UPDATE);
    virtual void evaluateZeroFuncs(const UPDATETYPE command = IContinuous::UNDEF_UPDATE);
    virtual bool evaluateConditions(const UPDATETYPE command);
    
    // Provide the right hand side (according to the index)
    virtual void getRHS(double* f);
    virtual void setRHS(const double* f);
    
    //Provide number (dimension) of zero functions
    virtual int getDimZeroFunc();
    //Provides current values of root/zero functions
    virtual void getZeroFunc(double* f);
    virtual void setConditions(bool* c);
    virtual void getConditions(bool* c);
    
    //Called to handle an event
    virtual void handleEvent(const bool* events);
    //Checks if a discrete variable has changed and triggers an event
    virtual bool checkForDiscreteEvents();
    virtual bool isStepEvent();
    //sets the terminal status
    virtual void setTerminal(bool);
    //returns the terminal status
    virtual bool terminal();
    
    
    
    // M is regular
    virtual bool isODE();
    // M is singular
    virtual bool isAlgebraic();
    
    virtual int getDimTimeEvent() const;
    //gibt die Time events (Startzeit und Frequenz) zuruck
    virtual void getTimeEvent(time_event_type& time_events);
    //Wird vom Solver zur Behandlung der Time events aufgerufen (wenn zero_sign[i] = 0  kein time event,zero_sign[i] = n  Anzahl von vorgekommen time events )
    virtual void handleTimeEvent(int* time_events);
    /// Set current integration time
    virtual void setTime(const double& time);
    
    // System is able to provide the Jacobian symbolically
    virtual bool provideSymbolicJacobian();
    
    virtual bool stepCompleted(double time);
    virtual bool stepStarted(double time);
    
    
    /// Provide boolean variables
    virtual void getBoolean(bool* z);
    /// Provide integer variables
    virtual void getInteger(int* z);
    /// Provide real variables
    virtual void getReal(double* z);
    /// Provide real variables
    virtual void getString(std::string* z);
    /// Provide boolean variables
    virtual void setBoolean(const bool* z);
    /// Provide integer variables
    virtual void setInteger(const int* z);
    /// Provide real variables
    virtual void setReal(const double* z);
    /// Provide real variables
    virtual void setString(const std::string* z);
    virtual bool getCondition(unsigned int index);
    
    boost::shared_ptr<IAlgLoopSolverFactory> getAlgLoopSolverFactory();
    boost::shared_ptr<ISimData> getSimData();
    
protected:
    //Methods:
    void initializeAlgloopSolverVariables();
    void initializeJacAlgloopSolverVariables();
    void deleteAlgloopSolverVariables();
    void deleteJacAlgloopSolverVariables();
    void initializeAlgloopSolverVariables_0();
    void deleteAlgloopSolverVariables_0();
    bool isConsistent();
    //Called to handle all events occured at same time
    bool handleSystemEvents(bool* events);
    //Saves all variables before an event is handled, is needed for the pre, edge and change operator
    void saveAll();
    
    void defineAlgVars();
    void defineDiscreteAlgVars();
    void defineIntAlgVars();
    void defineBoolAlgVars();
    void defineParameterRealVars();
    void defineParameterIntVars();
    void defineParameterBoolVars();
    void defineAliasRealVars();
    void defineAliasIntVars();
    void defineAliasBoolVars();
    void defineMixedArrayVars();
    
    void getJacobian(SparseMatrix& matrix);
    void deleteObjects();
    
    //Variables:
    boost::shared_ptr<EventHandling> _event_handling;
    boost::shared_ptr<DiscreteEvents> _discrete_events;
    
    //pointer to simVars-array to speedup simulation and compile time
    double* _pointerToRealVars;
    int* _pointerToIntVars;
    bool* _pointerToBoolVars;
    
     /*parameter real vars*/
     #define _e _pointerToRealVars[5]
     #define _g _pointerToRealVars[6]
     /*parameter int vars*/
     /*parameter bool vars*/
    /*string parameter variables*/
     /*string alias variables*/
     /*external variables*/
     /*alias real vars*/
     /*alias int vars*/
      /*alias bool vars*/
     /*string algvars*/
    //Variables saved for pre, edge and change operator
     /*real algvars*/
    /*discrete algvars*/
    #define _v_new _pointerToRealVars[4]
     /*int algvars*/
     #define _n_bounce _pointerToIntVars[0]
    /*bool algvars*/
    #define _$whenCondition1 _pointerToBoolVars[0]
    #define _$whenCondition2 _pointerToBoolVars[1]
    #define _$whenCondition3 _pointerToBoolVars[2]
    #define _flying _pointerToBoolVars[3]
    #define _impact _pointerToBoolVars[4]
     /*mixed array variables*/
    Functions* _functions;
    
    boost::shared_ptr<IAlgLoopSolverFactory> _algLoopSolverFactory;    ///< Factory that provides an appropriate solver




    /*! Index of the first equation. We use this to calculate the offset of an equation in the
       equation array given the index of the equation.*/
     int first_equation_index;
      /*! Equations*/
      FORCE_INLINE void evaluate_15();
      /*! Equations*/
      FORCE_INLINE void evaluate_16();
      /*! Equations*/
      FORCE_INLINE void evaluate_17();
      /*! Equations*/
      FORCE_INLINE void evaluate_18();
      /*! Equations*/
      FORCE_INLINE void evaluate_19();
      /*! Equations*/
      FORCE_INLINE void evaluate_20();
      /*! Equations*/
      FORCE_INLINE void evaluate_21();
      /*! Equations*/
      FORCE_INLINE void evaluate_22();
      /*! Equations*/
      FORCE_INLINE void evaluate_23();
    void defineDiscreteAlgVars_0();
    void defineIntAlgVars_0();
    void defineBoolAlgVars_0();
    void defineParameterRealVars_0();
    void defineConstVals();
 };