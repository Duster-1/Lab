
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846


using namespace std;


class TPair {
public:
  double x;
  double y;

  virtual TPair& operator+= (TPair const& cur) = 0;
  virtual TPair& operator-= (TPair const& cur) = 0;
  virtual TPair& operator*= (TPair const& cur) = 0;
};

class TComplex : public TPair {
public:

  TComplex(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  friend ostream& operator<< (ostream& out, const TComplex& obj);

  TPair& operator+= (TPair const& cur) override {
    this->x += cur.x;
    this->y += cur.y;

    return *this;
  }
  TPair& operator-= (TPair const& cur) override {
    this->x -= cur.x;
    this->y -= cur.y;

    return *this;
  }
  TPair& operator*= (TPair const& cur) override {
    double x1 = this->x;
    double y1 = this->y;

    double x2 = cur.x;
    double y2 = cur.y;

    this->x = ((x1 * x2) - (y1 * y2));
    this->y = ((x1 * y2) + (x2 * y1));

    return *this;
  }


  TComplex operator+(TComplex obj)
  {
    return TComplex(this->x + obj.x, this->y + obj.y);
  }
  TComplex operator-(TComplex obj)
  {
    return TComplex(this->x - obj.x, this->y - obj.y);
  }
  TComplex operator/(TComplex obj)
  {
    double x1 = this->x;
    double y1 = this->y;

    double x2 = obj.x;
    double y2 = obj.y;


    double first = ((x1 * x2) + (y1 * y2)) / (pow(x2, 2) + pow(y2, 2));
    double second = ((x2 * y1) - (x1 * y2)) / (pow(x2, 2) + pow(y2, 2));

    return TComplex(first, second);
  }
  TComplex operator*(TComplex obj)
  {
    double x1 = this->x;
    double y1 = this->y;

    double x2 = obj.x;
    double y2 = obj.y;

    return TComplex((x1 * x2) - (y1 * y2), ((x1 * y2) + (x2 * y1)));
  }

  void operator =(const TComplex& obj) {
    this->x = obj.x;
    this->y = obj.y;
  }

  double getArgument() {

    if (this->x > 0 && this->y >= 0) {
      return atan(this->y / this->x);
    }
    else if (this->x < 0 && this->y >= 0) {
      return PI - atan(abs(this->y / this->x));
    }
    else if (this->x < 0 && this->y < 0) {
      return PI + atan(abs(this->y / this->x));
    }
    else if (this->x > 0 && this->y < 0) {
      return 2 * PI - atan(abs(this->y / this->x));
    }
    else if (this->x == 0 && this->y > 0) {
      return PI / 2;
    }
    else if (this->x == 0 && this->y < 0) {
      return (3 * PI) / 2;
    }

  }
  double getModule() {
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
  }
  void getExtractRootN(int n, int k_max = 1) {

    double mod_complex = this->getModule();
    double arg_complex = this->getArgument();

    int k = 1;

    for (int k = 1; k <= k_max; k++) {

      double first_root_complex = pow(mod_complex, 1 / n) * (cos((arg_complex + 2 * PI * k) / 2));

      double second_root_complex = pow(mod_complex, 1 / n) * (sin((arg_complex + 2 * PI * k) / 2));


      cout << first_root_complex << "  +  i " << second_root_complex << "" << endl;
    }
  }
  double getN(int n) {
    return pow(this->getModule(), n) * ((cos(this->getArgument()) * n) + (sin(this->getArgument()) * n));
  }

  void print() {
    cout << this->x << "  +  i " << this->y << endl;
  }

  TComplex getCopy() {
    return TComplex(this->x, this->y);
  }

  ~TComplex() {

  }
};

ostream& operator<< (ostream& out, const TComplex& obj) {
  out << obj.x << "  +  i " << obj.y;
  return out;
}

class TRational : public TPair {

public:
  TRational(double x, double y) {
    this->x = x;
    this->y = y;
  }

TPair& operator+= (TPair const& cur) override {
  double y1 = cur.y;
  double y2 = this->y;
  
  while (y2 != y1) {
    if (y2 > y1) {
      y2 = y2 - y1;
    }
    else {
      y1 = y1 - y2;
    }
  }

  this->x = this->x + cur.x;
  this->y = y2;

  return *this;
}
TPair& operator-= (TPair const& cur) override {
  double y1 = cur.y;
  double y2 = this->y;
  
  while (y2 != y1) {
    if (y2 > y1) {
      y2 = y2 - y1;
    }
    else {
      y1 = y1 - y2;
    }
  }

  this->x = this->x - cur.x;
  this->y = y2;

  return *this;
}
TPair& operator*= (TPair const& cur) override {
  this->x *= cur.x;
  this->y *= cur.y;

  return *this;
}
};

int main()
{
  TComplex i = TComplex(2, -4);
  i.getExtractRootN(3, 2);

  TComplex u = i;
  cout << u << endl;

  cout << u + i << endl;

  cout << u - i << endl;

  cout << u * i << endl;

  cout << u / i << endl;

  i += u;

  i.print();

  
}