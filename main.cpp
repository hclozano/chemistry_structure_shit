#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "main.h"
#include "extraction.h"
#include "bond_angle.h"
#include "dihedral_angle.h"
#include "elements.h"
#include "bond_length.h"
//#include "bond_number.h"

using namespace std;
/**
 * @mainpage The Gaussian Optimization Analytical Tool (GOAT)
 *
 * Welcome to the Gaussian Optimization Analytical Tool (GOAT) documentation site!
 * Users may find relevant info related to this program, a program designed to provide
 * structural analyses of biomolecules successfully optimized using Gaussian software.
 *
 * @short   Main program
 * @file    main.cpp
 * @author  Kate Charbonnet, Hannah Lozano, and Thomas Summers
 * @param   none
 * @return  0 on success
 *
 * The purpose of this program is to provide preliminary structural information on biomolecules
 * optimized using Gaussian computational chemistry software.  Structural and chemical properties
 * identified include: element identification, bond length, bond order, central angles, and torsional
 * angles.  Input of the file to be analyzed will result in an output file listing all the structural
 * information of the biomolecule.
 */

int main(int argc, char* argv[])
{
    ofstream logfile;
    fstream bond_angle;
    fstream dihedral_angle;
    fstream bond_length;

    //Check that inputfile was directed into the command line
    if (argc < 2)
    {
        cout << "Error: Inputfile not specified in command line\n";
        return 1;
    }

    //Generate a logfile
    logfile.open("log.txt");
    if (!logfile.is_open())
    {
        cout << "Error: Unable to open the logfile.";
        return 3;
    } else {
        logfile << "Logfile for Gaussian Optimization Analytical Tool" << endl;
    }

    //Extract the raw coordinates from the inputfile in the commandline
    Extraction molecule(argv[1]);

    //Clean the coords file
    molecule.trim_coords(2);
    
    //Open the file bond_length.cpp and check that it opened
    bond_length.open("bond_length.cpp");
    if (!bond_length.is_open()) {
         cout << "Erorr: Unable to open bond_length file.";
	 return 1;
    }
    
    //Close the file bond_length.cpp
    bond_length.close();
    cout << "Bond length calculation complete." ;

    //Generate the 2D array of the coordinates
    molecule.array_coords();

    //Calculate the model's total mass
    double model_mass;
    double calculate_total_mass();
    cout << "Beginning calculation of the total mass of the model." << endl;
    model_mass = calculate_total_mass();
    if (model_mass == 0) {
        cout << "Error: Mass calculated to be zero." << endl;
        logfile << "Error: Mass calculated to be zero." << endl;
        logfile.close();
        return 4;
    } else {
        cout << scientific << "Total mass of model: " << model_mass << " amu" << endl;  
    }

    //Calculate the model's center of mass
    double xcoord, ycoord, zcoord;
    double calc_prod_coords_mass(int);

    xcoord = calc_prod_coords_mass(2);
    ycoord = calc_prod_coords_mass(3);
    zcoord = calc_prod_coords_mass(4);

    xcoord /= model_mass;
    ycoord /= model_mass;
    zcoord /= model_mass;

    cout << "Model's Center of Mass coordinates: " << endl
         << xcoord << "     " << ycoord << "     " << zcoord << endl;
 
    //Open the file bond_angle.cpp and check that it opened
    bond_angle.open("bond_angle.cpp");
    if (!bond_angle.is_open()) {
        cout << "Error: Unable to open file bond_angle.";
        return 1;
    }
    //Close the file bond_angle.cpp
    bond_angle.close();
    cout << "Bond angle calculation complete." << endl;
    return 0;
    
    //Open the file dihedral_angle.cpp and check that it opened
    dihedral_angle.open("dihedral_angle.cpp");
    if (!dihedral_angle.is_open()) {
        cout << "Error: Unable to open file dihedral_angle.";
        return 1;
    }
    //Close the file dihedral_angle.cpp
    dihedral_angle.close();
    cout << "Dihedral angle calculation complete.";
    return 0;
}
