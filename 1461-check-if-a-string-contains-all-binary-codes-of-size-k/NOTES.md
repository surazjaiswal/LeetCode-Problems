return false;
}
return true;
}
void generateBins(int k){
for(int i=0;i<(1<<k);i++){
int n = i, j=k-1, m=k-1;
string bin = "0";
while(m--)
bin += "0";
while(n){
if(n&1){
// bin = "1" + bin;
bin[j--]='1';
}
else{
// bin = "0" + bin;
bin[j--]='0';
}
n >>= 1;
}
bins.push_back(bin);
}
}
};
```