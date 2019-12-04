#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;


//HELPER FUNCTION
float distanceBetweenPoints(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
}

class AstroObservation
{
    public:
    static vector<AstroObservation>celestialList;
    static vector<pair<int,int>>positionList;
    static int validObservations;
    static int invalidObservations;
    static int avgLatitude;
    static int avgLongitude;
    static int avgTime;
    string name;
    int latitude,longitude;
    int day,month,year;
    int check;
    int area;
    int convertDays;
    vector<pair<int,int>>boundingBox;

    AstroObservation(string name,int latitude,int longitude,int date)
    {
        this->area=0;
        this->name=name;
        this->latitude=latitude;
        this->longitude=longitude;
        
        getDate(date);  //DAYS CONVERSION DONE HERE
        this->check=checkValidity();
        if(this->check==1)
        {
            this->boundingBox.pb(mp(this->latitude,this->longitude));
            checkRepetedName();
            computeArea();
            AstroObservation::positionList.pb(mp(this->latitude,this->longitude));
            AstroObservation::celestialList.pb(*this);
            AstroObservation::validObservations++;
        }
        else
        {
            AstroObservation::invalidObservations++;
        }
    }

    static void printMaxArea()
    {
        int max=-1;
        for(auto i=AstroObservation::celestialList.begin();i!=AstroObservation::celestialList.end();i++)
        {
            if((i->area) > max)
            {
                max=i->area;
            }
        }
        vector<AstroObservation>commonArea;
        for(auto i=AstroObservation::celestialList.begin();i!=AstroObservation::celestialList.end();i++)
        {
            if((i->area)==max)
            {
                commonArea.pb(*i); //PUSHING OBJECTS WITH THE SAME AREA OF BOUNDING BOX
            }
        }
        
        
        for(auto i=commonArea.begin();i!=commonArea.end();i++)
        {
            cout<<i->name<<" ";
        }
        cout<<endl;
    }

    //COMPUTE AREA FOR CELESTIAL BODY
    void computeArea()   
    {
        if(this->boundingBox.size()==1)
            this->area=0;
        else
        {
          
            //FIND MIN AND MAX
            int latMin=this->boundingBox[0].first;
            int lonMin=this->boundingBox[0].second;

            int latMax=this->boundingBox[0].first;
            int lonMax=this->boundingBox[0].second;
            
            

            for(int i=1;i<this->boundingBox.size();i++)
            {
                //SET MINIMUM
                if(this->boundingBox[i].first <latMin)
                {
                    latMin=this->boundingBox[i].first;
                }
                if(this->boundingBox[i].second <lonMin)
                {
                    lonMin=this->boundingBox[i].second;
                }

                //SET MAXIMUM
                if(this->boundingBox[i].first >latMax)
                {
                    latMax=this->boundingBox[i].first;
                }
                if(this->boundingBox[i].second >lonMax)
                {
                    lonMax=this->boundingBox[i].second;
                }
            }
            this->area=(abs(latMax-latMin)*abs(lonMax-lonMin));
        } 
    }

    void checkRepetedName()  //WILL DO ADDITION IN THE BOUNDING BOX
    {
        for(auto i=AstroObservation::celestialList.begin();i!=AstroObservation::celestialList.end();i++)
        {
            if(i->name ==this->name)
            {
                this->boundingBox.pb(mp(i->latitude,i->longitude));
            }
        }
    }

    //SET VALUES HERE
    static void getAverageLatitude()
    {
        int total=0;
        for(auto i=AstroObservation::positionList.begin();i!=AstroObservation::positionList.end();i++)
        {
            total+=i->first;
        }
        AstroObservation::avgLatitude=total/AstroObservation::positionList.size();
    }


    static void getAverageLongitude()
    {
        int total=0;
        for(auto i=AstroObservation::positionList.begin();i!=AstroObservation::positionList.end();i++)
        {
            total+=i->second;
        }
        AstroObservation::avgLongitude=total/AstroObservation::positionList.size();
    }

    static void getAverageTime()
    {
        int total=0;
        for(auto i=AstroObservation::celestialList.begin();i!=AstroObservation::celestialList.end();i++)
        {
            total+=i->convertDays;
        }
        AstroObservation::avgTime=total/AstroObservation::celestialList.size();
    }

    //RETURN INDEX IN THE LIST WHICH HAS CLOSEST POSITION
    static int closestDistance()
    {
        AstroObservation::getAverageLatitude();
        AstroObservation::getAverageLongitude();

        //cout<<"The averages are "<<endl;
        //cout<<AstroObservation::avgLatitude<<"----"<<AstroObservation::avgLongitude<<endl;

        int p=1;
        int returnValue=0; //STARTING INDEX
        int px=AstroObservation::positionList[0].first;
        int py=AstroObservation::positionList[0].second;
        float minDist=distanceBetweenPoints(AstroObservation::avgLatitude,AstroObservation::avgLongitude,px,py);
        auto iter=AstroObservation::positionList.begin()+1;
        for(auto i=iter;i!=AstroObservation::positionList.end();i++)
        {
            px=i->first;
            py=i->second;
            float distance=distanceBetweenPoints(AstroObservation::avgLatitude,AstroObservation::avgLongitude,px,py);
           // cout<<"The distances are "<<distance<<endl;
            if(distance < minDist)
            {
                minDist=distance;
                returnValue=p;  //INDEX
            }
            p++;
        }
        return returnValue;
    }

    static int closestTime()
    {
        AstroObservation::getAverageTime();
        //cout<<"The average days count is "<<AstroObservation::avgTime<<endl;
        int difference=abs(AstroObservation::celestialList[0].convertDays-AstroObservation::avgTime);
        int store=0;
        for(int i=1;i<AstroObservation::celestialList.size();i++)
        {
            int cal=abs(AstroObservation::avgTime - AstroObservation::celestialList[i].convertDays);
            if(cal < difference)
            {
                store =i;
                difference=cal;
            }
        }   
        return store;     
    }


    //SORT ACC. TO DATE WHEN OBSERVED
    static void sortData()
    {
        sort(AstroObservation::celestialList.begin(),AstroObservation::celestialList.end(),
        [](AstroObservation a,AstroObservation b)
        {
            if(a.year < b.year)
            {
                return 1;
            }
            else if(a.year==b.year)
            {
                if(a.month<b.month)
                {
                    return 1;
                }
                else if(a.month==b.month)
                {
                    if(a.day < b.day)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }   
                }
                else
                {
                    return 0;
                }   
            }
            else
            {
                return 0;
            }
        }
        );
    }


    void getDate(int date)
    {
        int year=date%10000;
        date=date/10000;
        int month=date%100;
        date=date/100;
        int day=date;

        this->year=year;
        this->month=month;
        this->day=day;

        int yearsPassed         =     this->year-1-1584; //THE YEAR WHEN CALENDAR WAS INVENTED
        int leapsTillPrevious   =     (this->year-1-1584)/4;
        int nonLeaps            =     yearsPassed-leapsTillPrevious;
        int daysTotal           =     leapsTillPrevious*366 + nonLeaps*365 + this->day;
        
        int monthGiven=this->month-1;
        int month31=0;
        int month30=0;
        for(int i=1;i<=monthGiven;i++)
        {
            if(i<=7)
            {
                if(i%2==1)
                {
                    month31++;
                }
                else if(i%2==0 && i!=2)  //NOT TAKING FEBRUARY
                {
                    month30++;
                }
            }
            if(i>=8)
            {
                if(i%2==0)
                    month31++;
                else
                    month30++;
            }
        }
        //MONTH CONTRIBUTION TO DAYS
        if(this->year%4==0)
        {
            if(monthGiven > 2)  //FEB PASSED
            {
                daysTotal+=daysTotal+30*month30+31*month31+29;
            }
            else
            {
                daysTotal+=daysTotal+30*month30 + 31*month31+28;
            }
        }
        else  //NOT A LEAP YEAR
        {
            if(monthGiven > 2)
            {
                daysTotal+=daysTotal + 30*month30 + 31*month31 +28;
            }
            else
            {   
                //NOT FEB
                daysTotal+=daysTotal + 30*month30 + 31*month31;
            }
        }
        //cout<<"The 30 day months are "<<month30<<endl;
        //cout<<"The 31 day months are "<<month31<<endl;
        //cout<<"The leap years are "<<leapsTillPrevious<<endl;
        //cout<<"The non-leaps are "<<nonLeaps<<endl;
        this->convertDays=daysTotal;
        //cout<<"The days are "<<this->convertDays<<endl;
    }




    int checkValidity()
    {
       if(this->latitude >=-90 && this->latitude<=90 && this->longitude>=-180 && this->longitude<=180 && this->name.size()==3)
       {
           int count=0;
           for(int i=0;i<=2;i++)
           {
                if(this->name[i]>='A' && this->name[i]<='Z')
                {
                    count++;
                }
           }
           if(count==3)
           {
                int value=checkDate();
                if(value==0)
                    return 0;
                else
                    return 1;
           }
           else
           {
               return 0;
           }
       } 
       else
       {
           return 0;
       }
    }
    int checkDate()
    {
        //DONE EXCEPT FOR FEBRUARY
        if(this->month>=1 && this->month<=12 && this->year>=1584) //ROUGH ESTIMATE
        {
            if(this->month==1 || this->month==3 || this->month==5 || this->month==7 || this->month==8 || this->month==10 || this->month==12)
            {
                if(this->day >=1 && this->day <=31)
                {
                   return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            else if(this->month==4 || this->month==6 || this->month==9 || this->month==11) 
            {
                if(this->day >=1 && this->day<=30)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            else if(this->month==2)
            {
                return this->checkYear();
            }
        }
        else
        {
            return 0;
        }  
    }
    int checkYear() //CALLED WHEN IT IS FEBRUARY
    {
        if(this->year%4==0) //LEAP YEAR
        {
            if(this->day >=1 && this->day <=29)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else                // NOT A LEAP YEAR
        {  
            if(this->day>=1 && this->day <=28)
            {
                return 1;
            }
            else
            {
                return 0;
            }   
        }
        
    }
};

int AstroObservation::avgLatitude=0;
int AstroObservation::avgLongitude=0;
int AstroObservation::validObservations=0;
int AstroObservation::invalidObservations=0;
int AstroObservation::avgTime=0;
vector<AstroObservation>AstroObservation::celestialList;
vector<pair<int,int>>AstroObservation::positionList;

int32_t main()
{
    //ASSUMING THAT CALENDAR WAS INVENTED IN 1584(LEAP YEAR) TO GET CLOSEST TIME PLANET SIGHTING
    while(1)
    {
        string x;
        cin>>x;
        if(x=="##")
        {
            break;
        }
        string name=x;
        int latitude,longitude;
        cin>>latitude>>longitude;
        int date;
        cin>>date;
        char chr;
        cin>>chr;
        AstroObservation(name,latitude,longitude,date);
    }
    AstroObservation::sortData();
   
    int p=AstroObservation::closestDistance();
    int time=AstroObservation::closestTime();
    
    cout<<AstroObservation::validObservations<<endl;
    cout<<AstroObservation::validObservations+AstroObservation::invalidObservations<<endl;
    cout<<"The closest body is ";
    cout<<AstroObservation::celestialList[p].name<<endl;
    cout<<"The closest time body is ";
    cout<<AstroObservation::celestialList[time].name<<endl;
    cout<<"Max area ";
    AstroObservation::printMaxArea();
}


//MONTH-LIST

//JAN 1
//FEB 2
//MAR 3
//APR 4
//MAY 5
//JUN 6
//JUL 7
//AUG 8
//SEP 9
//OCT 10
//NOV 11
//DEC 12