#include <stdio.h>
#include <stdbool.h>


struct date{
	int month;
	int day;
	int year;
};

bool isLeap(struct date d);
int numberofDays(struct date d);


int main(int argc, char const *argv[])
{
	struct date today,tomorrow;

	printf("Enter today's date (mm dd yyyy):\n");
	scanf("%i %i %i", &today.month, &today.day, &today.year);

	if( today.day != numberofDays(today) ){
		tomorrow.day=today.day+1;
		tomorrow.month=today.month;
		tomorrow.year=today.year;
	}else if( today.month == 12 ){
		tomorrow.day=1;
		tomorrow.day=1;
		tomorrow.day=today.year+1;
	}else{
		tomorrow.day=1;
		tomorrow.month=today.month+1;
		tomorrow.year=today.year;
	}

	printf("Tomorrow's date is %i-%i-%i\n",
			tomorrow.month, tomorrow.day, tomorrow.year);

	return 0;
}


int numberofDays(struct date d){
	int days;
	const int daysPerMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	if(d.month == 2 && isLeap(d) )
		days=29;
	else
		days=daysPerMonth[d.month-1];

	return days;
}

bool isLeap(struct date d){
	bool leap=false;

	if( (d.year%4 == 0 && d.year%100 != 0) || d.year%400 == 0 )
		leap=true;

	return leap;
}
		
		
		

