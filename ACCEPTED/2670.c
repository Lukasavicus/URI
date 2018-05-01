// Lukasavicus 2670
#include <stdio.h>

int main(){
	
	int a, b, c, va, vb, vc, gt;

	scanf("%d %d %d", &a, &b, &c);

	va = (b * 2) + (c * 4);
	vb = (a * 2) + (c * 2);
	vc = (a * 4) + (b * 2);

	if(va <= vb && va <= vc)		gt = va;
	else if(vb <= va && vb <= vc)	gt = vb;
	else if(vc <= va && vc <= vb)	gt = vc;

	printf("%d\n", gt);

	return 0;
}