//This program calculates Pi using a monte carlo method.
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

double magnitude(double,double);

int main (int argc, char *argv[]) {
  ofstream outfile_in ("in_circle.dat"); //file thing
  ofstream outfile_out ("out_circle.dat");
  //variable declaration statements:
  if (argc!=3){
    cout << "Two argument needed: -<number of samples> -<1 plots graph>. Will abort." << endl;
    return -1;
  }
  int n = atoi(argv[1]);// convert char to int
  int plot_graph = atoi(argv[2]);
  const double Pi= 4 * atan(1);
  double n_inside_circle = 0.0;
  double n_total = n_total = (double) n;
  double x;
  double y; 
  double r;
  double calculated_pi;
  //end variable declarations.

  cout.precision(10);
  outfile_in.precision(6);
  outfile_out.precision(6);
  cout.setf(ios::fixed,ios::floatfield);
  outfile_in.setf(ios::fixed,ios::floatfield);
  outfile_out.setf(ios::fixed,ios::floatfield);

  srand((unsigned)time(NULL));

  //main do loop
    for (int i=n; i>0; i--){
      x = rand() % 1000001;
      x = x/1000000;
      y = rand() % 1000001;
      y = y/1000000;
      r = magnitude(x,y);
      if (r <= 1.0)
       	{
	  n_inside_circle = n_inside_circle + 1.0;
       	  outfile_in << x; outfile_in <<" ";
	  outfile_in << y; outfile_in << endl;
        }
      else
	{
	  outfile_out << x; outfile_out <<" ";
	  outfile_out << y; outfile_out << endl;
	}
    }
     
    calculated_pi =  4*n_inside_circle/n_total;
    cout << "Pi = "; cout << calculated_pi << endl;
    cout << "Ture Pi = "; cout << Pi << endl;
    outfile_in.close();
    outfile_out.close();
    if (plot_graph == 1){
      system("gnuplot 'pi.gp'");
    }
    return 0;

//Function finds the magnitude of r.
}
double magnitude(double xvalue, double yvalue) {
  return sqrt((xvalue*xvalue)+(yvalue*yvalue));
}
  
