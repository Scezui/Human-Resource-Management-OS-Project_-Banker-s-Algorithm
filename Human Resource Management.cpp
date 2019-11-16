#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
int np,nr,clm[200][200],allo[200][200],avl[200],flag=0,flag11=0,y,c=0,i=0,count=0,fc=0,chkpcmp[200],minc,cp,a=0,tempr[200],flag2;
cout<<"Enter the number of Project:\n";
cin>>np;


for(int i=0;i<np;i++)
{
	chkpcmp[i]=0;
}


cout<<"Enter the number of resources:\n";
cin>>nr;


cout<<"\nEnter all the claimed requirements of Project:\n";
for(int i=1;i<=np;i++)
{
        cout<<"\nFor Project "<<i<<" :\n";
        for(int j=1;j<=nr;j++)
        {cout<<"Number of R"<<j<<" resources:";
        cin>>clm[i-1][j-1];}
}
cout<<"\nEnter number of allocated resources:\n";
for(int i=1;i<=np;i++)
{
        cout<<"\nFor Project "<<i<<" :\n";
        for(int j=1;j<=nr;j++)
        {cout<<"Number of R"<<j<<" resources:";
        cin>>allo[i-1][j-1];}
}

cout<<"\nEnter the available number of resources:\n";
for(int i=1;i<=nr;i++)
{
cout<<"R"<<i<<":";
cin>>avl[i-1];
}

//Logic start


for(i=0;i<np;i++)
{
    if(chkpcmp[i]==0) {
    
    
   for(int j=0;j<nr;)
  {
   
   
     for(int y=0;y<nr;y++)
        {
             if(clm[i][y]==0)
             count++;
             else {count=0;break;}
        }
        
        if(count==nr) {count=0;break;}
      
      
   
     if((clm[i][j]-allo[i][j])<=avl[j])
   {
             
      if(j==nr-1)
       {
       flag=1;
      fc++;
       for(int k=0;k<nr;k++)
       {avl[k]=avl[k]+allo[i][k];}
       
       for(int k=0;k<nr;k++)
       {allo[i][k]=0;}
             
        for(int k=0;k<nr;k++)
       {clm[i][k]=0;}
       
     cout<<"\nProject "<<"P"<<i+1<<" is completed\n";	chkpcmp[i]=1;
     if(fc==np) cout<<"\nHence, all the Projectes have completed successfully";
     break;
       }           
     j++;  
   }
    
     else 
     break;
  }
if(flag==1)
{i=-1;flag=0;}
}}


// Buy Resources

 while(fc!=np){
 	
  for(int k=0;k<nr;k++)
{
	tempr[k]=0;
}

 	
 flag2=1;a=0;

cout<<endl<<"Unsafe state has occured."<<endl;

	for(cp=0;cp<np;cp++)
	{
		
		  if(chkpcmp[cp]==0) 
		  {
		  	
		   for(int j=0;j<nr;j++)
		   {
		   	
		   	if(clm[cp][j]>allo[cp][j]+avl[j])
		   	a=a+clm[cp][j]-(allo[cp][j]+avl[j]);
		   		   	
		   }
		   
		   if(flag2==1)
		   	{minc=a+1;flag2=0;}
		   	
		  
		   if(a<=minc)
		   {
		   	minc=a;
		   			   	
		   	for(int t=0;t<nr;t++)
		   	{
		   	    if(clm[cp][t]>allo[cp][t]+avl[t])
		        tempr[t]=clm[cp][t]-(allo[cp][t]+avl[t]);
		   				   		
		   	}
		   	
		   	
		   }
		   
		
		
		
		
          }
	
	
	
	
	
	
	
    }
    

cout<<endl<<"Hire following resources:"<<endl<<endl;
for(i=0;i<nr;i++)
{

cout<<tempr[i]<<" resources of R"<<i+1<<endl;

}


for(i=0;i<nr;i++)
{

avl[i]=avl[i]+tempr[i];
	
}


for(i=0;i<np;i++)
{
    if(chkpcmp[i]==0) {
    
    
   for(int j=0;j<nr;)
  {
   
   
     for(int y=0;y<nr;y++)
        {
             if(clm[i][y]==0)
             count++;
             else {count=0;break;}
        }
        
        if(count==nr) {count=0;break;}
      
      
   
     if((clm[i][j]-allo[i][j])<=avl[j])
   {
             
      if(j==nr-1)
       {
       flag=1;
      fc++;
       for(int k=0;k<nr;k++)
       {avl[k]=avl[k]+allo[i][k];}
       
       for(int k=0;k<nr;k++)
       {allo[i][k]=0;}
             
        for(int k=0;k<nr;k++)
       {clm[i][k]=0;}
       
     cout<<"\nProject "<<"P"<<i+1<<" is completed\n";	chkpcmp[i]=1;
     if(fc==np) cout<<"\nHence, all the Projectes have completed successfully.";
     break;
       }           
     j++;  
   }
    
     else 
     break;
  }
if(flag==1)
{i=-1;flag=0;}
}}

}



getch();
return 0;
}
   
