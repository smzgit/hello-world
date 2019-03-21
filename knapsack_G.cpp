#include <iostream>
#include <set>
#include <string>
#include <bits/stdc++.h> 

using namespace std ;

class activity{
	public :
	string name ;
	int w ;
	int p ;
	float r ;
	
};

bool operator <(activity const & a, activity const & b)
{
    return a.r < b.r;
}

int main(){
	
	int M ;
	set<string> selected ;
	float profit  ;
	cout<<"	Enter the size of the KnapSack ( <=48 ): " ;
	cin>>M ;
	activity arr[11] = {
				{"Obj_1",1,4,0.0},
				{"Obj_2",3,5,0.0},
				{"Obj_3",2,6,0.0},
				{"Obj_4",5,7,0.0},	
				{"Obj_5",3,10,0.0},	
				{"Obj_6",5,9,0.0},	
				{"Obj_7",7,11,0.0},	
				{"Obj_8",8,11,0.0},		
				{"Obj_9",9,12,0.0},	
				{"Obj_10",2,14,0.0},	
				{"Obj_11",3,16,0.0}} ;
				
				
	int n = sizeof(arr)/sizeof(arr[0]); 
	for(int i = 0; i<n ; i++)
		arr[i].r = 1.0*arr[i].p/arr[i].w ;
		
	cout<<"\n	Objects  (Name,Weight,Profit,Ratio[Profit/Weight]): \n" ;
	for(int i = 0; i<n ; i++){

			cout<<" 	"<<arr[i].name;
			cout<<"		"<<arr[i].w;
			cout<<"		"<<arr[i].p;
			cout<<"		"<<arr[i].r;
			cout<<endl;
		
		
		
	}
  
    sort(arr, arr + n);
    
    cout<<"\n	AFTER SORTING ...\n	Objects  (Name,Weight,Profit,Ratio[Profit/Weight]: \n" ;
	for(int i = 0; i<n ; i++){

			
			cout<<" 	"<<arr[i].name;
			cout<<"		"<<arr[i].w;
			cout<<"		"<<arr[i].p;
			cout<<"		"<<arr[i].r;
			cout<<endl;
		
		
		
	}
	
	while(M != 0) {
	    cout<<" M : "<<M<<endl ;
		float d = 0.0 ;
		float rt,wg = 0.0;
		for(int i = n-1; i>=0 ; i--){
			
			if(M<arr[i].w){
				selected.insert((arr[i].name)) ;
				d = M*1.0/arr[i].w ;
				cout<<" D :" <<d<<endl;
				rt = d*arr[i].p ;
				wg = d*arr[i].w ;
				cout<<" pro of d :" <<rt<<"   wgt :  "<<wg<<endl;
				break ;}
			else{
			
			profit = profit + arr[i].p ; 
			M = M - arr[i].w ;cout<<" M : "<<M<<endl ;
			selected.insert(arr[i].name) ;
			if(M==0)
				break;
			
			}
							
		}
		
		profit = profit + rt ;
		M = M - wg ;
		
		
		
	}
	
	
    cout<<"\n_____________________________________"<<endl;
    cout<<"	selected Objects :\n\n";
    	for(string x : selected)
    		cout<<"  	"<<x<<endl;
    	cout<<"\n\tMax Profit : "<<	profit;
	cout<<"\n_____________________________________\n"<<endl;
	
	
 	return 0 ;
}
