int moneyMade(vector[] amounts, int[] centsPerDollar, int finalResult){
int sum=0;
for(i=0;i<sz(amounts);i++)if(i!=finalResult)sum+=amounts[i]*100;
return sum-amounts[finalResult]*centsPerDollar[finalResult];
}
