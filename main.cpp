/**
** @file Sunroof and HVAC Control System
* @author Swapna V(135554), Sushmitha Gowda(135551)
* @date 28/02/2018
* @version 1.0
*
* @brief genesis training, Exe 1, I/O intergration code
*
* @section DESCRIPTION
*
* This code contains 2 subsystems - Sunroof and HVAC.
* The Sunroof subsystem has 2 modes(Manual and Automatic). In Manual mode, the sunroof can be opened by one level and closed by one level.
* In Automatic mode, the sunroof opens and closes completely, during these functions, if any object is detected then the sunroof open completely.
* It also checks if the rain intensity is greater than the threshold and closes the sunroof, if open.
* The HVAC system can control the temperature(cooler/heater), vents(face,leg,face and leg, and defogger),mode of the fan speed
**/
/* ************* HEADER FILES DECLARATION ************* */

#include <iostream>
#include "Sunroof.cpp"
#include "HVAC.cpp"
#include <stdio.h>

using namespace std;

/* The main function controls the flow of the code */

int main()
{
    Sunroof obj;
    HVAC h;
    int engineState,mode,inputChoice,acmode,hvacinput,tempinput,ventinput;
    while(1)
    {
        cout<<"Enter the state of the Engine(Enter 1 for ON and 0 for OFF):"<<endl;
        cin>>engineState;
        try
        {
            if(engineState == 0)
            {
                throw "Engine is OFF.\nPlease switch ON the engine.";
            }
            else if(engineState == 1)
            {
                while(1)
                {
                    cout<<"1.Sunroof System(Enter 0)\n2.HVAC System(Enter 1)\n3.Exit(Enter 2)\nEnter which system you want to control:"<<endl;
                    cin>>inputChoice;
                    try
                    {
                        if(inputChoice == 0)
                        {
                            cout<<"THE SUNROOF IS CLOSED INITIALLY"<<endl;
                            cout<<"1.Manual Mode(Enter 0)\n2.Automatic Mode(Enter 1)\n3.Previous Menu(Enter 2)\n4.Exit(Enter 3)\nEnter your choice:"<<endl;
                            cin>>mode;
                            try{
                            if(mode == 0)
                                obj.manualMode();
                            else if(mode == 1)
                                obj.automaticMode();
                            else if(mode == 2)
                                continue;
                            else if(mode == 3)
                                exit(1);
                            else
                                throw "Invalid Input.Please enter a valid input(0 or 1)";
                            }
                            catch(const char* msg)
                            {
                                cout<<msg<<endl;
                            }
                        }
                        else if(inputChoice == 1)
                        {
                            while(1)
                            {
                                cout<<"Enter the state of the AC(Enter 1 for ON and 0 for OFF):\nNote enter 2 to go back to previous menu"<<endl;
                                cin>>acmode;
                                try
                                {
                                    if(acmode == 0)
                                    {
                                        throw "AC is either OFF or the input given is invalid.\nPlease switch ON the AC.";
                                    }
									else if(acmode == 1)
									{
										while(1)
										{
											cout<<"Enter the function desired of the HVAC:\n1.Temperature Module 2.Speed of the Fan 3.Mode of Vents 4.Previous Menu 5.Exit\n"<<endl;
											cin>>hvacinput;
											try
											{
												if(hvacinput == 1)
												{
													while(1)
													{
														cout<<"1.Heater Mode(Enter 1)\n2.Cooler Mode(Enter 2)\n3.Previous Menu(Enter 3)\nEnter the mode:"<<endl;
														cin>>tempinput;
														try
														{
															if(tempinput==1)
															{
																h.HeaterModule();
															}
															else if(tempinput ==2)
															{
																h.CoolerModule();
															}
															else if(tempinput == 3)
                                                                break;
															else
															{
																throw "Invalid mode. Please try again!\n";
															}
														}
														catch(const char* msg)
														{
															cout<<msg<<endl;
														}
													}
												}
												else if(hvacinput == 2)
												{
													h.fanspeed();
												}
												else if(hvacinput == 3)
												{
													while(1)
													{
														cout<<"Vent types\n1.Face vent(Enter 1)\n2.Foot vent(Enter 2)\n3.Face and foot vent(Enter 3)\n4.Defogger(Enter 4)\n5.Previous Menu(Enter 5)\nEnter your choice:"<<endl;
														cin>>ventinput;
														if(ventinput == 1 || ventinput == 2|| ventinput ==4)
														{
															h.venttypes(ventinput);
														}
														else if (ventinput ==3)
														{
															h.venttypes(ventinput,'b');

														}
														else if(ventinput == 5)
                                                            break;
														else
														{
															cout<<"Invalid input.Please try again!\n";
														}
													}
												}
												else if(hvacinput == 4)
													break;
												else if(hvacinput == 5)
													exit(1);
												else
												{
														throw "Invalid input.Please try again!\n";
												}
											}
											catch(const char* msg)
											{
												cout<<msg<<endl;
											}
										}
									}
									else if(acmode == 2)
                                        break;
								}
								catch(const char* msg)
								{
									cout<<msg<<endl;
								}
							}
                        }
                        else if(inputChoice == 2)
                        {
                            exit(1);
                        }
                        else
                            throw "Invalid Input.Please enter a value between 0-2";
                    }
                    catch(const char* msg)
                    {
                        cout<<msg<<endl;
                    }
                }
            }
            else
                throw "Invalid Input. Please enter a valid input(0 or 1)";

        }
        catch(const char* msg)
        {
            cout<<msg<<endl;
        }
    }
    return 0;

}
