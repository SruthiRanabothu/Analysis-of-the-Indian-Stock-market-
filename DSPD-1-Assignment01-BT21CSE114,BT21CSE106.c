
#include<stdio.h>
#include<string.h>
struct day {
    double open;
    double high;
    double low;
    double close;
    double volume;
};
struct company{
    struct day d[100];
    char comp_name[50];
};

struct Date {
    int d, m, y;
};
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
int countLeapYears(struct Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return ((years+1) / 4) - ((years+1) / 100) + ((years+1) / 400);
}
int getDifference(struct Date dt1,struct Date dt2)
{
	int i;
    long int n1 = dt1.y * 365 + dt1.d;
    for ( i = 0; i < dt1.m - 1; i++){
        n1 = n1 + monthDays[i];
    n1 = n1 + countLeapYears(dt1);
}
    long int n2 = dt2.y * 365 + dt2.d;
    for (i = 0; i < dt2.m - 1; i++){
        n2 = n2 + monthDays[i];
    n2 = n2 + countLeapYears(dt2);
}
    return (n2 - n1);
}
 void printarray(struct company arr[],int n,int p){
 	int i;
    for( i=0;i<10;i++){
        printf("For %s: volume=%lf,closeprice= %lf\n",arr[i].comp_name,arr[i].d[p].volume,arr[i].d[p].close);
    }
}

void bubblesort(struct company arr[] ,int n,int p){
	int i,j;
    for( j=0;j<10-1;j++){
        for(i=0;i<10-1-j;i++){
            if(arr[i].d[p].volume>arr[i+1].d[p].volume){
                struct company temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            else if(arr[i].d[p].volume==arr[i+1].d[p].volume){
                if(arr[i].d[p].close>arr[i+1].d[p].close){
                        struct company temp=arr[i];
                    arr[i]=arr[i+1];
                arr[i+1]=temp;
                }
            }
        }
    }
}
void printarray_f(struct company arr[10],float sum[],int n){
	int i;
    for( i=0;i<10;i++){
        printf("overall performance is for %s is %f\n",arr[i].comp_name,sum[i]);
    }
}
void bubblesort_f(struct company arr[10],float sum[],int n){
	int i,j;
    for( j=0;j<9;j++){
        for( i=0;i<10-1-j;i++){
            if(sum[i]>sum[i+1]){
            struct company tempo=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=tempo;
            float temp=sum[i];
            sum[i]=sum[i+1];
            sum[i+1]=temp;
            }
        }
    }
}
int main(){
    int n;
    double percentchange;
    struct Date dt1 = { 1, 11, 2022 };
    struct Date dt2 = { 3, 11, 2022 };
    n=getDifference(dt1, dt2);
    printf("Number of days between the two given dates are %d\n",n);
    printf("----------------------------------------------\n");
    struct company arr[10];
    int i,j;
    for( i=0;i<10;i++){
        printf("please enter company name: ");
        scanf("%s",arr[i].comp_name);
    for( j=0;j<n;j++){
        printf("Enter info for %s on day %d\n",arr[i].comp_name,j+1);
        scanf("%lf",&arr[i].d[j].open);
        scanf("%lf",&arr[i].d[j].high);
        scanf("%lf",&arr[i].d[j].low);
        scanf("%lf",&arr[i].d[j].close);
        scanf("%lf",&arr[i].d[j].volume);
    }
}
printf("-----------------------------------------------------------\n");
for(i=0;i<10;i++){
    percentchange=(((arr[i].d[n-1].close)-(arr[i].d[0].close))*100)/arr[i].d[n-1].close;
    printf("percentagechange in the price of stock from start date to end date for %s is %lf\n",arr[i].comp_name,percentchange);
}
printf("--------------------------------------------------------\n");
    int p;
    printf("\nEnter the day on which stock is to be sorted :\n");
    scanf("%d",&p);
    if(p<n && p>=0){
    bubblesort(arr,n,p);
    printarray(arr,n,p);
    }
    else{
        printf("Enter a valid day\n");
    }
    printf("--------------------------------------------------------\n");
    float percent_loss_or_profit;
    for( i=0;i<10;i++){
    percent_loss_or_profit=(((arr[i].d[n-1].close)-(arr[i].d[0].open))*100)/(arr[i].d[n-1].close);
    if(percent_loss_or_profit>0){
        printf("Profit percentage for %s is %f\n",arr[i].comp_name,percent_loss_or_profit);
    }
    else{
    percent_loss_or_profit=(-1)*percent_loss_or_profit;
    printf("Loss percentage for %s is %f\n",arr[i].comp_name,percent_loss_or_profit);
    }
}
printf("---------------------------------------------------------------\n");
    float performance[10];
    for( j=0;j<10;j++)
    {
        performance[j] = (((arr[j].d[n-1].close)-(arr[j].d[0].open))*100)/(arr[j].d[n-1].close);
    }
    
    int indexhigh=-1,max=-99999999;
    for(i=0;i<10;i++)
    {
        if(max<performance[i])
        {
            max=performance[i];
               indexhigh=i;
        }
        }
   // printf("Performance index for highest performing company is %d\n", indexhigh);
    int indexlow = -1,min=99999999;
    for( i=0;i<10;i++)
    {
        if(min>performance[i])
        {
              min=performance[i];
              indexlow=i;
    }
    }
   // printf("Performance index for lowest performing company is %d\n", indexlow);
    
    if(indexhigh==0)
    {
        printf("SBIN has highest performing stock in this duration\n");
    }
    else if(indexhigh==1)
    {
        printf("TATAMOTORS has highest performing stock in this duration\n");
    }
    else if(indexhigh==2)
    {
        printf("PNB has highest performing stock in this duration\n");
    }
    else if(indexhigh==3)
    {
        printf("YESBANK has highest performing stock in this duration\n");
    }
    else if(indexhigh==4)
    {
        printf("TECHM has highest performing stock in this duration\n");
    }
    else if(indexhigh==5)
    {
        printf("INFY has highest performing stock in this duration\n");
    }
    else if(indexhigh==6)
    {
        printf("TCS has highest performing stock in this duration\n");
    }
    else if(indexhigh==7)
    {
        printf("TITAN has highest performing stock in this duration\n");
    }
    else if(indexhigh==8)
    {
        printf("ONGC has highest performing stock in this duration\n");
    }
    else if(indexhigh==9)
    {
        printf("IOC has highest performing stock in this duration\n");
    }
    
    if(indexlow==0)
    {
        printf("SBIN has lowest performing stock in this duration\n");
    }
    else if(indexlow==1)
    {
        printf("TATAMOTORS has lowest performing stock in this duration\n");
    }
    else if(indexlow==2)
    {
        printf("PNB has lowest performing stock in this duration\n");
    }
    else if(indexlow==3)
    {
        printf("YESBANK has lowest performing stock in this duration\n");
    }
    else if(indexlow==4)
    {
        printf("TECHM has lowest performing stock in this duration\n");
    }
    else if(indexlow==5)
    {
        printf("INFY has lowest performing stock in this duration\n");
    }
    else if(indexlow==6)
    {
        printf("TCS has lowest performing stock in this duration\n");
    }
    else if(indexlow==7)
    {
        printf("TITAN has lowest performing stock in this duration\n");
    }
    else if(indexlow==8)
    {
        printf("ONGC has lowest performing stock in this duration\n");
    }
    else if(indexlow==9)
    {
        printf("IOC has lowest performing stock in this duration\n");
    }
    printf("------------------------------------------------------------\n");
    float sum[10];
    for( j=0;j<10;j++){
        for( i=0;i<n-1;i++){
            sum[j]=sum[j]+(((arr[j].d[i+1].close)-arr[j].d[i].close)*arr[j].d[i+1].volume)/arr[j].d[i+1].close;
        }
    }
    bubblesort_f(arr,sum,n);
    printarray_f(arr,sum,n);
    printf("-------------------------------------------------------------\n");
    
    float avg[10];
    
    for(j=0;j<10;j++){
        float num=0;
        float den=0;
        for( i=0;i<n;i++)
        {
            num=num+((arr[j].d[i].close)*(arr[j].d[i].volume));
            den=den+(arr[j].d[i].volume);
        }
        avg[j] = num/(den*1.0);
        printf("The avg value of %s is %f\n",arr[j].comp_name,avg[j]);
    }
}
