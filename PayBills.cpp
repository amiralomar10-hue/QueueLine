#include <iostream>
#include"clsQueueLine.h"
int main()
{
	clsQueueLine PayBillsQueue("A0",10);
	clsQueueLine SubscriptionsQueue("B0", 5);
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	PayBillsQueue.issueTicket();
	cout << "\nPay Bills Queue Info:\n";
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrinfTicketsLineRTL();
	PayBillsQueue.PrinfTicketsLineLTR();
	
	PayBillsQueue.PrintALLTickets();

	PayBillsQueue.ServeNextClient();

	cout << "\nPay Bills Queue after serving One Clients \n\n\n";
	PayBillsQueue.PrintInfo();

	SubscriptionsQueue.issueTicket();
	SubscriptionsQueue.issueTicket();
	SubscriptionsQueue.issueTicket();

	cout << "\nSubscriptions Queue Info:\n";
    
	SubscriptionsQueue.PrintInfo();

	SubscriptionsQueue.PrinfTicketsLineRTL();
	SubscriptionsQueue.PrinfTicketsLineLTR();

	SubscriptionsQueue.PrintALLTickets();

	SubscriptionsQueue.ServeNextClient();

	cout << "\nSubscriptions after serving One Clients \n\n\n";
	SubscriptionsQueue.PrintInfo();


}
