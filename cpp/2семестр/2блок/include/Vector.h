


class Vector {
private:
    double m_x = 0.0;
    double m_y = 0.0;

public:
    Vector operator+(const Vector& vec_2) const;
    Vector operator-(const Vector& vec_2) const;
    double operator*(const Vector& vec_2) const;
    
};

Vector 