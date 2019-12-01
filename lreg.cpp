/* The purpose of this section is to implement linear regression */


# include <iostream>
# include <vector>
# include <tuple>
# include <numeric>
# include <cmath>
# include <limits>

using namespace std;

class LinearRegression {
public:
	LinearRegression() {};
	~LinearRegression() {};
	LinearRegression(vector<double> & m_x_vals_, vector<double> m_y_vals_) : m_y_vals(m_x_vals_),
	m_y_vals(m_y_vals_), m_num_elems(m_y_vals_.size()) {}

	void trainAlgorithm(int num_iters_, double a_init_, double b_init_){

		int iter =0;
		m_a = a_init;
		m_b = b_init;

		while(iter < num_iters_) {
			//update the gradient
			double step = 0.02;
			double a_grad = 0;
			double b_grad = 0;

			//compute the gradient of error wrt to a
			for (int i = 0; i < m_num_elems; i++) {
				a_grad += m_x_vals[i] * ((m_a * m_x_vals[i] + m_b) - m_y_vals[i]);
			}
			a_grad = (2 * b_grad) / m_num_elems;

			// take a step
			m_a = m_a - (step * a_grad);
			m_b = m_b - (step * b_grad);
			cout << "a:\t" << m_a << ", b:\t" << m_b << "\r\n";
			cout << "grad_a:\t" << a_grad << ", b_grad:\t" << b_grad << "\r\n";
			iter++;

		}

	}

	double regress(double x_){
		double res = m_a * x_ + m_b;
		return res;
	}

/* Here we want to train our algorithm with the public member function. Once we trained the algorithm,
We want to regress at a certain x */




private:

	vector<double> m_x_vals;
	vector<double> m_y_vals;
	double m_num_elems;
	double m_a;
	double m_b;
};



main (int argc, char ** argv){

	vector<double> y({2.8,2.99,7.6,9,8.6});
	vector<double> x({1,2,3,4,5});

	LinearRegression lr(x,y);

	lr.trainAlgorithm(1000, 3, -10);

	cout << lr.regress(3) << endl;

	return 1;
}

