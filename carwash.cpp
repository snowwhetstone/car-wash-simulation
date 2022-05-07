#include <iostream> // Provides cout 
#include <cstdlib> // Provides EXIT_SUCCESS 
#include <queue> // Provides queue 
#include "washing.h" // Provides averager, bool_source, washer 
using namespace std; 

void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time) {
    cout << "Simulation strat! Now,let's see what we got!\n" << "---------------------------------------------------------------------\n" << endl;
    cout << "Seconds to wash one car: " << wash_time << endl;
    cout << "Probability of customer arrival during a second: ";
    cout << arrival_prob << endl;
    cout << "Total simulation seconds: " << total_time << endl;

    queue<unsigned int> coming_times; // coming customer¡¯s time period
    unsigned int info;                 // A value taken from the queue
    bool_source arrival(arrival_prob);
    washer machine(wash_time);
    averager wait_times;
    unsigned int current_second;
    //Do the work and make sure each step will be count by one second
    //first make sure people was coming,and than coyp the elemnet,after that start wash
    for (current_second = 1; current_second <= total_time; ++current_second)
    {
        // Check when someone has arrived.
        if (arrival.query()) {
            //copy element
            coming_times.push(current_second);
        }
        if ((!machine.is_busy()) && (!coming_times.empty()))
        {
            info = coming_times.front();
            coming_times.pop();
            wait_times.next_number(current_second - info);
            //after copy,star wash
            machine.start_washing();
        }
        // After processe ,one second was gone
        machine.one_second();
    }
    //when someone wash already
    while (!coming_times.empty()) {
        current_second++;
        // Check we can start washing car or not.
        if (!machine.is_busy())
        {
            info = coming_times.front();
            coming_times.pop();
            wait_times.next_number(current_second - info);
            machine.start_washing();
        }
        // After processe ,one second was gone
        machine.one_second();
    }
    // now we get output.
    cout << "\n\nThere is our final result:\n";
    cout << wait_times.how_many_numbers() << "customers served in this simulation" << endl;
    if (wait_times.how_many_numbers() > 0)
        cout << "Average wait " << wait_times.average() << " sec in simulation\n\n" << endl;
}

int main() {
    int wash_time, total_time;
    double arrival_prob;
    cout << "Please enter the wash time for each car by second:" << endl;
    cin >> wash_time;
    cout << "Please enter the probability of someone coming(please make sure the number between 0~1):" << endl;
    cin >> arrival_prob;
    cout << "Please enter total time for simulation by second:" << endl;
    cin >> total_time;
    cout << "\n" << endl;
    car_wash_simulate(wash_time,  arrival_prob,  total_time);

    system("pause");
	return 0;
}
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time);
