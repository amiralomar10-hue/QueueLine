#pragma once
#include<iostream>
#include<queue>
#include"clsDate.h"
#include<stack>
class clsQueueLine
{

private:
	struct stTicket
	{
		string AccountOrder;
		string Date;
		int wating_Clients;
		int _WaitingTimeTicket;
	};

	string _Perfix;
	int _Total_Tickets;
	int _WaitingTime;
	queue<stTicket> _QueTickets;

	void _PrintTicket(stTicket &Ticket)
	{
		cout << "\n\t\t\t\t\t---------------------------------------\n";
		cout << "\n\t\t\t\t\t\t\t" << Ticket.AccountOrder;
		cout << "\n\n\t\t\t\t\t\t" << Ticket.Date;
		cout << "\n\n\t\t\t\t\t\t Waiting Clients = " << Ticket.wating_Clients;
		cout << "\n\n\t\t\t\t\t\t    Serve Time In\n\t\t\t\t\t\t     " << Ticket._WaitingTimeTicket << " Minutes.";
		cout << "\n\n\n\t\t\t\t\t---------------------------------------\n";

	}

public:

	clsQueueLine(string perfix, int WaitingTime)
	{
		_Perfix = perfix;
		_WaitingTime = WaitingTime;
		_Total_Tickets = 0;
	}

	void issueTicket()
	{

		_Total_Tickets++;
		stTicket NewTickets;
		NewTickets.AccountOrder = _Perfix + to_string(_Total_Tickets);
		NewTickets.Date = clsDate::GetSystemDateTimeString();
		NewTickets.wating_Clients = _QueTickets.size();
		NewTickets._WaitingTimeTicket = _QueTickets.size() * _WaitingTime;
		_QueTickets.push(NewTickets);
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t\t\t---------------------------------------\n";
		cout << "\n\t\t\t\t\t\t       Queue Info \n";
		cout << "\n\t\t\t\t\t---------------------------------------\n";
		cout << "\n\t\t\t\t\t   Perfix = " << _Perfix;
		cout << "\n\t\t\t\t\t   Total Tickets = " << _Total_Tickets;
		cout << "\n\t\t\t\t\t   Served Clients = " << _Total_Tickets - _QueTickets.size();
		cout << "\n\t\t\t\t\t   Waiting Clients = " << _QueTickets.size();
		cout << "\n\t\t\t\t\t---------------------------------------\n";

	}

	void PrinfTicketsLineRTL()
	{

		queue<stTicket> Temp = _QueTickets;
		
		string PrintTicket = "\n\n\t\t\t\tTickets = ";
		while (!Temp.empty())
		{
			PrintTicket += Temp.front().AccountOrder + "   <--   ";
			
			Temp.pop();
		}
		
		cout  << PrintTicket;

	}

	void PrinfTicketsLineLTR()
	{

		queue<stTicket> Temp = _QueTickets;
		stack<stTicket> Temp2;
		string PrintTicket = "\n\n\t\t\t\tTickets = ";
		while (!Temp.empty())
		{
			Temp2.push(Temp.front());

			
			Temp.pop();
		}

		while (!Temp2.empty())
		{
			PrintTicket += Temp2.top().AccountOrder + "   -->   ";
			Temp2.pop();
		}


		cout  << PrintTicket;

	}

	void PrintALLTickets()
	{
		cout << "\n\n\t\t\t\t\t\t    ---Tickets---\n";
		queue<stTicket> Temp = _QueTickets;

		while (!Temp.empty())
		{
			_PrintTicket(Temp.front());
			Temp.pop();
			
		}


	}

	void ServeNextClient()
	{
		if (!_QueTickets.empty())
		{
			_QueTickets.pop();
		}
		
	}
};

