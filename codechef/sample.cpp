#include <iostream>
int main() {
    long int T;
    std::cin>>T;
    while(T--){
        int n;
        std::cin>>n;
        std::cout<<(((4*n)*(4*n-1)*(4*n-2)/6)-(4*n*(n-1)*(n-2)/6))<<std::endl;
    }

}
