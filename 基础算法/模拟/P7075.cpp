#include <bits/stdc++.h>
#include <ostream>
using namespace std;
int n;
struct Date{
    int year;
    int month;
    int day;

    ostream& operator<<(ostream& out) const{
        out << day << ' ' << month << ' ';
        if(year > 0) out << year;
        else out << -year << ' ' << "BC";
        return out;
    }
};
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getJDate_1(Date d){
    int ans = 0;
    if(d.year < 0){
        int temp_year = d.year - (-4713);
        int count = ceil(1.0f * temp_year / 4);
        ans = temp_year * 365 + count;
        temp_year = -d.year;
    
        if(temp_year % 4 == 1 && d.month > 2){
            ans += 1;
        }

        for(int i = 0; i < d.month - 1; i++){
            ans += month[i];
        }

        ans += d.day;
        return ans;
    }
    else{
        return -1;
    }
    
}
int main(){
    cin >> n;
    cout << getJDate_1({-1, 12, 30});
}