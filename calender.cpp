#include<iostream>
using namespace std;
class year
{
    private:
    int year;
    int month;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthnames[12] = {"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOMBER","NOVEMBER","DECEMBER"};

    public:
    void setyear(int year, int month)
    {
        this->year = year;
        this->month = month;
    }
    int getyear()
    {
        return year;
    }
    int getmonth()
    {
        return month;
    }
    int getmonths()
    {
        int month = getmonth();
        int year = getyear();
        if (year %4 ==0 && month == 2)
        {
            return  29;
        }
        else
        {
            return months[month-1];
        }
    }
    int firstjan()
    {
        int year = getyear();
        int i = 5*((year-1)%4);
        i+=4*((year-1)%100);
        i+=6*((year-1)%400);
        i = i%7;
        return i;
    }
    int leap(int year, int count)
    {
        int month = getmonth();
        if ( year % 4 ==0 && month >2)
        {
            count += 1;
        }
        else
        {
            count = count;
        }
        return count;
    }
    int whichmonth()
    {
        int mon = getmonth();
        if (mon == 1)
        {
            return firstjan();
        }
        else
        {
            int count = firstjan();
            for (int i=0;i<mon-1; i++)
            {
                count += months[i];
            }
            int count1 = leap(getyear(), count);
            return count1 % 7;
        }
    }
    void printmonth()
    {
        int mon = getmonth();
        cout <<"\n"<<monthnames[mon-1]<<"  "<<getyear()<<endl<<endl;
    }
};

class printer : public year
{
    public:
    void monthprint()
    {
        int days = getmonths();
        int fm = whichmonth();
        cout <<"MON\tTUE\tWED\tTHUR\tFRI\tSAT\tSUN"<<endl;
        int date = 1-fm;
        for (int r=0; r<6;r++)
        {
            for (int c=0; c<7;c++)
            {
                if (date <= 0)
                {
                    cout <<"\t";
                }
                else if(date > days)
                {
                    break;
                }
                else
                {
                    cout << date<<"\t";
                }
                date ++;
            }
            cout <<endl;
        }
    }
};

int main()
{
    printer p;
    int year, month;
    cout <<"Enter the year: ";
    cin >> year;
    cout <<"Enter the month: ";
    cin >> month;
    p.setyear(year, month);
    p.printmonth();
    p.monthprint();

    
}