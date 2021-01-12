

// Hawzin Mohammed (22007895)  CPE/ISE 351
//

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#define LINE_MAX 1024
using namespace std;


FILE *fp, *fo;

char line[LINE_MAX];
unsigned int proc[LINE_MAX][3];
unsigned int orginal_proc[LINE_MAX][3];
unsigned int temp[3];
int arr_index;
ofstream outfile;

//load information form file
void load_file()
{
	arr_index = 0;
	outfile.open("output.txt"); // for saving information

	cout << "process\n";
	outfile << "process\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";



	cout << "\nProcess\t\tBurst Time\tArrival Time\tPriority";
	outfile << "\nProcess\t\tBurst Time\tArrival Time\tPriority";

	if ((fp = fopen("input.txt", "r")) == NULL)
		cout << "File not Found";
	while (fgets(line, LINE_MAX, fp) != NULL) {
		//read from file
		sscanf(line, "%d:%d:%d\n", &proc[arr_index][0], &proc[arr_index][1], &proc[arr_index][2]);
		//copy to another aaray for backup
		orginal_proc[arr_index][0] = proc[arr_index][0];
		orginal_proc[arr_index][1] = proc[arr_index][1];
		orginal_proc[arr_index][2] = proc[arr_index][2];

		cout << "\nP[" << arr_index + 1 << "]" << "\t\t" << proc[arr_index][0] << "\t\t" << proc[arr_index][1] << "\t\t" << proc[arr_index][2];
		//
		outfile << "\nP[" << arr_index + 1 << "]" << "\t\t" << proc[arr_index][0] << "\t\t" << proc[arr_index][1] << "\t\t" << proc[arr_index][2];

		arr_index++;
	}
	fclose(fp);

	cout << "\n-------------------------------------\n\n";
	outfile << "\n-------------------------------------\n\n";

	outfile.close();
}


//copy orginal info
void copy_orginal_info()
{

	for (int i = 0; i<arr_index; i++)
	{
		proc[i][0] = orginal_proc[i][0];
		proc[i][1] = orginal_proc[i][1];
		proc[i][2] = orginal_proc[i][2];
	}

}


//print information
void print_info()
{
	cout << "\n************** After Sort**********\n";
	for (int i = 0; i<arr_index; i++)
	{

		cout << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << proc[i][1] << "\t\t" << proc[i][2];

	}
	cout << "\n***********************\n";

}



// sort array depending on Brust time
void sort_brust()
{

	copy_orginal_info();

	///////////////sort depending on Brust time  time///////////////////////
	for (int i = 0; i < arr_index; i++) {
		for (int j = 1; j < (arr_index - i); j++) {

			if (proc[j - 1][0] > proc[j][0]) {
				//swap elements  

				memcpy(temp, proc[j - 1], sizeof(proc[j]));
				memcpy(proc[j - 1], proc[j], sizeof(proc[j]));
				memcpy(proc[j], temp, sizeof(proc[j]));

			}

		}
	}

	//if you wnat see array after sort remove bellow comment

	//print_info();

}

// sort array depending on Arrival time
void sort_arrival()
{


	copy_orginal_info();

	///////////////sort depending on Arrival///////////////////////
	for (int i = 0; i < arr_index; i++) {
		for (int j = 1; j < (arr_index - i); j++) {

			if (proc[j - 1][1] > proc[j][1]) {
				//swap elements  

				memcpy(temp, proc[j - 1], sizeof(proc[j]));
				memcpy(proc[j - 1], proc[j], sizeof(proc[j]));
				memcpy(proc[j], temp, sizeof(proc[j]));

			}

		}
	}

	//if you wnat see array after sort remove bellow comment

	//print_info();




}

// sort array depending on Priority
void sort_priority()
{
	copy_orginal_info();

	///////////////sort depending on Priority///////////////////////
	for (int i = 0; i < arr_index; i++) {
		for (int j = 1; j < (arr_index - i); j++) {

			if (proc[j - 1][2] < proc[j][2]) {
				//swap elements  

				memcpy(temp, proc[j - 1], sizeof(proc[j]));
				memcpy(proc[j - 1], proc[j], sizeof(proc[j]));
				memcpy(proc[j], temp, sizeof(proc[j]));

			}

		}
	}

	//if you wnat see array after sort remove bellow comment

	//print_info();


}


// preemptive_mode get info from user 
void scheduling_method_preemptive_mode()
{
	arr_index = 0;
	outfile.open("output.txt"); // for saving information



	int tat[LINE_MAX], avg_time = 0, avg_turnaround = 0, wt[LINE_MAX], i, j, total = 0;;

	arr_index = 0;

	int p = 0;
	cout << "Please enter the number of process:\n";
	cin >> p;

	arr_index = p;

	for (i = 0; i<arr_index; i++)
	{
		cout << "\n*********************************\n";
		cout << "\nPlease enter [ Burst Time ] for Process [" << i + 1 << "] : ";
		cin >> proc[i][0];
		cout << "\nPlease enter [ Arrival Time ] for Process [" << i + 1 << "] : ";
		cin >> proc[i][1];
		cout << "\nPlease enter [ Priority ]for Process [" << i + 1 << "] : ";
		cin >> proc[i][2];



	}

	cout << "\nprocess\n";
	outfile << "\nprocess\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";



	cout << "\nProcess\t\tBurst Time\tArrival Time\tPriority";
	outfile << "\nProcess\t\tBurst Time\tArrival Time\tPriority";



	for (int i = 0; i<arr_index; i++)
	{
		//copy to another aaray for backup
		orginal_proc[i][0] = proc[i][0];
		orginal_proc[i][1] = proc[i][1];
		orginal_proc[i][2] = proc[i][2];


		cout << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << proc[i][1] << "\t\t" << proc[i][2];
		//
		outfile << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << proc[i][1] << "\t\t" << proc[i][2];


	}







	cout << "\nFirst Come, First Served Scheduling\n";
	outfile << "\nFirst Come, First Served Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	sort_arrival();
	/////////////////First Come, First Served Scheduling///////////////////


	cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	outfile << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

	//calculating waiting time
	for (i = 1; i<arr_index; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += proc[j][0];
	}


	//calculating turnaround time
	for (i = 0; i < arr_index; i++)
	{
		tat[i] = proc[i][0] + wt[i];
		avg_time += wt[i];
		avg_turnaround += tat[i];
		cout << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];
		outfile << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];

	}


	avg_time /= i;
	avg_turnaround /= i;
	cout << "\n\nAverage Waiting Time:" << avg_time;
	cout << "\nAverage Turnaround Time:" << avg_turnaround;
	cout << "\n\n**************************************************\n";

	outfile << "\n\nAverage Waiting Time:" << avg_time;
	outfile << "\nAverage Turnaround Time:" << avg_turnaround;
	outfile << "\n\n**************************************************\n";




	/////////////////Shortest-Job-First Scheduling////////////////////

	cout << "Shortest-Job-First Scheduling\n";
	outfile << "Shortest-Job-First Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	float avg_wt, avg_tat;



	sort_brust(); // sort brust time 

	for (i = 1; i<arr_index; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += proc[j][0];

		total += wt[i];
	}

	avg_wt = (float)total / arr_index;
	total = 0;

	cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	outfile << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

	for (i = 0; i<arr_index; i++)
	{
		tat[i] = proc[i][0] + wt[i];
		total += tat[i];

		cout << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];
		outfile << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];


	}

	avg_tat = (float)total / arr_index;

	cout << "\n\nAverage Waiting Time:" << avg_wt;
	cout << "\nAverage Turnaround Time:" << avg_tat;
	cout << "\n\n**************************************************\n";



	outfile << "\n\nAverage Waiting Time:" << avg_wt;
	outfile << "\nAverage Turnaround Time:" << avg_tat;
	outfile << "\n\n**************************************************\n";





	/////////////////Priority Scheduling////////////////////

	sort_priority();

	cout << "Priority Scheduling\n";
	outfile << "Priority Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	//calculate waiting time
	for (i = 1; i<arr_index; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += proc[j][0];

		total += wt[i];
	}

	avg_wt = total / arr_index;      //average waiting time
	total = 0;

	cout << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
	outfile << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";

	for (i = 0; i<arr_index; i++)
	{
		tat[i] = proc[i][0] + wt[i];     //calculate turnaround time
		total += tat[i];
		cout << "\nP[" << i << "]\t\t  " << proc[i][0] << "\t\t    " << wt[i] << "\t\t\t" << tat[i];
		outfile << "\nP[" << i << "]\t\t  " << proc[i][0] << "\t\t    " << wt[i] << "\t\t\t" << tat[i];

	}

	avg_tat = total / arr_index;     //average turnaround time
	cout << "\n\nAverage Waiting Time=" << avg_wt;
	cout << "\nAverage Turnaround Time=" << avg_tat;
	cout << "\n\n**************************************************\n";


	outfile << "\n\nAverage Waiting Time=" << avg_wt;
	outfile << "\nAverage Turnaround Time=" << avg_tat;
	outfile << "\n\n**************************************************\n";





	/////////////////Round-Robin Scheduling////////////////////


	cout << "Round-Robin Scheduling\n";
	outfile << "Round-Robin Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	for (i = 0; i<arr_index; i++)
	{
		proc[i][0] = orginal_proc[i][0];
		proc[i][1] = orginal_proc[i][1];
		proc[i][2] = orginal_proc[i][2];
	}


	int count, time, remain, flag = 0, time_quantum;
	int wait_time = 0, turnaround_time = 0, rt[LINE_MAX];

	remain = arr_index;
	for (count = 0; count<arr_index; count++)
	{

		rt[count] = proc[count][0];
	}

	cout << "Please Enter Time Quantum:";
	outfile << "Please Enter Time Quantum:";
	scanf("%d", &time_quantum);
	cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";

	outfile << time_quantum;
	outfile << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";

	for (time = 0, count = 0; remain != 0;)
	{
		if (rt[count] <= time_quantum && rt[count]>0)
		{
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		}
		else if (rt[count]>0)
		{
			rt[count] -= time_quantum;
			time += time_quantum;
		}
		if (rt[count] == 0 && flag == 1)
		{
			remain--;

			cout << "\nP[" << count + 1 << "]" << "\t\t" << proc[count][0] << "\t\t" << time - proc[count][1] - proc[count][0] << "\t\t" << time - proc[count][1];

			outfile << "\nP[" << count + 1 << "]" << "\t\t" << proc[count][0] << "\t\t" << time - proc[count][1] - proc[count][0] << "\t\t" << time - proc[count][1];

			wait_time += time - proc[count][1] - proc[count][0];
			turnaround_time += time - proc[count][1];
			flag = 0;
		}
		if (count == arr_index - 1)
			count = 0;
		else if (proc[count + 1][1] <= time)
			count++;
		else
			count = 0;
	}

	cout << "\n\nAverage Waiting Time=" << wait_time*1.0 / arr_index;
	cout << "\nAverage Turnaround Time=" << turnaround_time*1.0 / arr_index;
	cout << "\n\n**************************************************\n";

	outfile << "\n\nAverage Waiting Time=" << wait_time*1.0 / arr_index;
	outfile << "\nAverage Turnaround Time=" << turnaround_time*1.0 / arr_index;
	outfile << "\n\n**************************************************\n";



	outfile.close();


}


// non_preemptive_mode load from file 
void scheduling_method_non_preemptive_mode()
{
	// load information from file
	load_file();

	outfile.open("output.txt", fstream::app); // for saveing the result

	cout << "First Come, First Served Scheduling\n";
	outfile << "First Come, First Served Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	sort_arrival();
	/////////////////First Come, First Served Scheduling///////////////////

	int tat[LINE_MAX], avg_time = 0, avg_turnaround = 0, wt[LINE_MAX], i, j, total = 0;;

	cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	outfile << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

	//calculating waiting time
	for (i = 1; i<arr_index; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += proc[j][0];
	}


	//calculating turnaround time
	for (i = 0; i < arr_index; i++)
	{
		tat[i] = proc[i][0] + wt[i];
		avg_time += wt[i];
		avg_turnaround += tat[i];
		cout << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];
		outfile << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];

	}


	avg_time /= i;
	avg_turnaround /= i;
	cout << "\n\nAverage Waiting Time:" << avg_time;
	cout << "\nAverage Turnaround Time:" << avg_turnaround;
	cout << "\n\n**************************************************\n";

	outfile << "\n\nAverage Waiting Time:" << avg_time;
	outfile << "\nAverage Turnaround Time:" << avg_turnaround;
	outfile << "\n\n**************************************************\n";




	/////////////////Shortest-Job-First Scheduling////////////////////

	cout << "Shortest-Job-First Scheduling\n";
	outfile << "Shortest-Job-First Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	float avg_wt, avg_tat;



	sort_brust(); // sort brust time 

	for (i = 1; i<arr_index; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += proc[j][0];

		total += wt[i];
	}

	avg_wt = (float)total / arr_index;
	total = 0;

	cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
	outfile << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

	for (i = 0; i<arr_index; i++)
	{
		tat[i] = proc[i][0] + wt[i];
		total += tat[i];

		cout << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];
		outfile << "\nP[" << i + 1 << "]" << "\t\t" << proc[i][0] << "\t\t" << wt[i] << "\t\t" << tat[i];


	}

	avg_tat = (float)total / arr_index;

	cout << "\n\nAverage Waiting Time:" << avg_wt;
	cout << "\nAverage Turnaround Time:" << avg_tat;
	cout << "\n\n**************************************************\n";



	outfile << "\n\nAverage Waiting Time:" << avg_wt;
	outfile << "\nAverage Turnaround Time:" << avg_tat;
	outfile << "\n\n**************************************************\n";





	/////////////////Priority Scheduling////////////////////

	sort_priority();

	cout << "Priority Scheduling\n";
	outfile << "Priority Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	//calculate waiting time
	for (i = 1; i<arr_index; i++)
	{
		wt[i] = 0;
		for (j = 0; j<i; j++)
			wt[i] += proc[j][0];

		total += wt[i];
	}

	avg_wt = total / arr_index;      //average waiting time
	total = 0;

	cout << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
	outfile << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";

	for (i = 0; i<arr_index; i++)
	{
		tat[i] = proc[i][0] + wt[i];     //calculate turnaround time
		total += tat[i];
		cout << "\nP[" << i << "]\t\t  " << proc[i][0] << "\t\t    " << wt[i] << "\t\t\t" << tat[i];
		outfile << "\nP[" << i << "]\t\t  " << proc[i][0] << "\t\t    " << wt[i] << "\t\t\t" << tat[i];

	}

	avg_tat = total / arr_index;     //average turnaround time
	cout << "\n\nAverage Waiting Time=" << avg_wt;
	cout << "\nAverage Turnaround Time=" << avg_tat;
	cout << "\n\n**************************************************\n";


	outfile << "\n\nAverage Waiting Time=" << avg_wt;
	outfile << "\nAverage Turnaround Time=" << avg_tat;
	outfile << "\n\n**************************************************\n";





	/////////////////Round-Robin Scheduling////////////////////


	cout << "Round-Robin Scheduling\n";
	outfile << "Round-Robin Scheduling\n";
	cout << "-------------------------------------\n";
	outfile << "-------------------------------------\n";

	for (i = 0; i<arr_index; i++)
	{
		proc[i][0] = orginal_proc[i][0];
		proc[i][1] = orginal_proc[i][1];
		proc[i][2] = orginal_proc[i][2];
	}


	int count, time, remain, flag = 0, time_quantum;
	int wait_time = 0, turnaround_time = 0, rt[LINE_MAX];

	remain = arr_index;
	for (count = 0; count<arr_index; count++)
	{

		rt[count] = proc[count][0];
	}

	cout << "Please Enter Time Quantum:";
	outfile << "Please Enter Time Quantum:";
	scanf("%d", &time_quantum);
	cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";

	outfile << time_quantum;
	outfile << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";

	for (time = 0, count = 0; remain != 0;)
	{
		if (rt[count] <= time_quantum && rt[count]>0)
		{
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		}
		else if (rt[count]>0)
		{
			rt[count] -= time_quantum;
			time += time_quantum;
		}
		if (rt[count] == 0 && flag == 1)
		{
			remain--;

			cout << "\nP[" << count + 1 << "]" << "\t\t" << proc[count][0] << "\t\t" << time - proc[count][1] - proc[count][0] << "\t\t" << time - proc[count][1];

			outfile << "\nP[" << count + 1 << "]" << "\t\t" << proc[count][0] << "\t\t" << time - proc[count][1] - proc[count][0] << "\t\t" << time - proc[count][1];

			wait_time += time - proc[count][1] - proc[count][0];
			turnaround_time += time - proc[count][1];
			flag = 0;
		}
		if (count == arr_index - 1)
			count = 0;
		else if (proc[count + 1][1] <= time)
			count++;
		else
			count = 0;
	}

	cout << "\n\nAverage Waiting Time=" << wait_time*1.0 / arr_index;
	cout << "\nAverage Turnaround Time=" << turnaround_time*1.0 / arr_index;
	cout << "\n\n**************************************************\n";

	outfile << "\n\nAverage Waiting Time=" << wait_time*1.0 / arr_index;
	outfile << "\nAverage Turnaround Time=" << turnaround_time*1.0 / arr_index;
	outfile << "\n\n**************************************************\n";



	outfile.close();


}

// non_preemptive_mode load from file 
void non_preemptive_mode()
{

	scheduling_method_non_preemptive_mode();

}

// show result that saved in file  
void show_result()
{
	// shown all result that stored in file
	if ((fo = fopen("output.txt", "r")) == NULL)
		cout << "File not Found";
	while (fgets(line, LINE_MAX, fo) != NULL) {
		cout << line;
	}
	fclose(fp);

}

// clear output file

void clear_file()
{
	outfile.open("output.txt");
	outfile << "";
	outfile.close();
}



int main()
{
	/////////load data from txt file/////////////
	clear_file();


	// infinet loop 
	while (true)
	{


		//////////////////////////////choosing Action//////////////////////////////////////
		cout << "Please Choose the Action by Inputing procber :" << endl;
		cout << "1) Scheduling Method" << endl;
		cout << "2) Preemptive Mode" << endl;
		cout << "3) Non-preemptive Mode" << endl;
		cout << "4) Show Result" << endl;
		cout << "5) End Program" << endl;

		////////////////////////////////////////////////////////////////////


		int chooes = 0;
		cout << "\nPlease enter your choose : ";
		cin >> chooes;
		switch (chooes)
		{
		case 1:
			cout << "\nScheduling Method\n" << endl;
			scheduling_method_non_preemptive_mode();
			break;

		case 2:
			cout << "\nPreemptive Mode\n" << endl;
			scheduling_method_preemptive_mode();
			break;

		case 3:
			cout << "\nNon-preemptive Mode\n" << endl;
			scheduling_method_non_preemptive_mode();
			break;
		case 4:
			cout << "\n ####################Strat Show Result#######################\n" << endl;
			show_result();
			cout << "\n ####################End Show Result#######################\n" << endl;
			break;

		case 5:
			cout << "\nEnd of Program\n" << endl;
			exit(0);
			break;

		default: cout << "Wrong Option you should enter between (1-5)" << endl;

		}

	}



	return 0;
}



