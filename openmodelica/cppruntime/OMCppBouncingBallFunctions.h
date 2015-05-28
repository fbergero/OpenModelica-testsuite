#pragma once

/*****************************************************************************
*
* Simulation code for FunctionCall functions generated by the OpenModelica Compiler.
*
*****************************************************************************/
//external functions
extern "C" {
}

class Functions
{
public:
  Functions(double& simTime, double* z, double* zDot, bool& initial, bool& terminate);
  ~Functions();
  //Modelica functions
  
  void Assert(bool cond,string msg);
  
  //Literals
   string _OMC_LIT0;
   string _OMC_LIT1;
private:
  //Function return variables
  double& _simTime;
  bool& _terminate;
  bool& _initial;
  double* __z;
  double* __zDot;
  /*extraFuncs*/
};