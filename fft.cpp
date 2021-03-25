// is this fft 
typedef complex<double> Complex;
const double PI=acos(-1);
const Complex I(0,1);
 
void fft(Complex *x, const int n, const bool idft=false) {
    static Complex *y = NULL; static int y_len = 0;
    if (y_len < n) {
	if (y) delete[] y;
	y_len = n;
	y = new Complex[y_len];
    }
    if (idft) {
	for (int p=0; p<n; p++) x[p] = conj(x[p]);
    }
    int nn = n, s = 1, eo = 0;
    for (; nn>1;) {
	const int m = nn / 2;
	const double theta = 2.0 * PI / nn;
	for (int p=0; p<m; p++) {
	    const Complex wp(cos(p * theta), -sin(p * theta));
	    for (int q=0; q<s; q++) {
		const Complex a = x[q + s * p];
		const Complex b = x[q + s * (p + m)];
		const Complex c = a - b;
		y[q + s * (p + p)] = a + b;
		y[q + s * (p + p + 1)] = Complex(
			c.real()*wp.real() - c.imag()*wp.imag(),
			c.real()*wp.imag() + c.imag()*wp.real());
		//y[q + s * (p + p + 1)] = (a - b) * wp;
	    }
	}
	nn = m; s += s; eo ^= 1;
	swap(x, y);
    }
    if (eo) {
	for (int q=0; q<s; q++) y[q] = x[q];
	swap(x, y);
    }
    if (idft) {
	double b = 1.0 / n;
	for (int p=0; p<n; p++) x[p] = conj(x[p]) * b;
    }
}





Complex A[1<<20] , B [ 1<<20] ;


// steps **********
 //fft( A , 1<<20) ;
 //fft(B , 1<<20  ) ;
 //for( int i=0; i < 1<<20 ; i ++) {
	//A[i] *= B[ i] ;
  //}
 
 //fft(A, 1<<20 , true );
 // A[ i].real() , A[i].real( val) ;// print and assign 
