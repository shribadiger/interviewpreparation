#include<iostream>
#include<vector>

int main() {
	int A[]={1,2,3,4,5,6};
	int B[]={1,2,3,4,5,6};

	for(int i=0;i<6;i++) {
		for(int j=0;j<6;j++) {
			if(A[i]<B[j]) {
				std::cout<<"\t("<<A[i]<<","<<B[j]<<")";
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}
