#ifndef VEHICLE_HPP_
#define VEHICLE_HPP_

#include <iostream>

class Vehicle {
  friend std::ostream &operator<<(std::ostream &, const Vehicle &);
  friend std::istream &operator>>(std::istream &, Vehicle &);
  friend bool operator<(const Vehicle &, const Vehicle &);
  friend bool operator>(const Vehicle &, const Vehicle &);
  friend bool operator==(const Vehicle &, const Vehicle &);

private:
  std::string _MODEL; // Название модели автомобиля
  double _FUEL[3]; // Расход топлива на трассе, в городе и смешанный
  size_t _SPEED;   // Максимальная скорость
  double _ENGINE_POWER; // Мощность двигателя

public:
  Vehicle(); // Конструктор по умолчанию
  Vehicle(const std::string &, const double *, const size_t &,
          const double &);  // Конструктор с параметрами
  Vehicle(const Vehicle &); // Конструктор копирования
  std::string get_model() const;
};

inline Vehicle::Vehicle()
    : _MODEL(""), _FUEL{0, 0, 0}, _SPEED(0), _ENGINE_POWER(0){};

inline Vehicle::Vehicle(const std::string &_MO, const double *_FU,
                        const size_t &_SP, const double &_ENP)
    : _MODEL(_MO), _FUEL{_FU[0], _FU[1], _FU[2]}, _SPEED(_SP),
      _ENGINE_POWER(_ENP){};

inline Vehicle::Vehicle(const Vehicle &_TMP)
    : _MODEL(_TMP._MODEL), _FUEL{_TMP._FUEL[0], _TMP._FUEL[1], _TMP._FUEL[2]},
      _SPEED(_TMP._SPEED), _ENGINE_POWER(_TMP._ENGINE_POWER){};

inline std::string Vehicle::get_model() const { return this->_MODEL; };

inline std::ostream &operator<<(std::ostream &os, const Vehicle &_TMP) {
  os << "Model: " << _TMP._MODEL << std::endl;
  os << "Fuel consumption" << std::endl
     << "highway: " << _TMP._FUEL[0] << " city: " << _TMP._FUEL[1]
     << " mixed: " << _TMP._FUEL[2] << std::endl;
  os << "Max speed: " << _TMP._SPEED << std::endl;
  os << "Engine power: " << _TMP._ENGINE_POWER << std::endl;

  return os;
}

inline std::istream &operator>>(std::istream &is, Vehicle &_TMP) {
  is >> std::ws; // очищаем буфер потока от лишних пробельных символов

  std::getline(is, _TMP._MODEL);

  for (int i = 0; i < 3; ++i)
    is >> _TMP._FUEL[i];

  is >> _TMP._SPEED;
  is >> _TMP._ENGINE_POWER;

  return is;
}

inline bool operator<(const Vehicle &_LTMP, const Vehicle &_RTMP) {
  return _LTMP._FUEL[2] <
         _RTMP._FUEL[2]; // Сравнение по смешанному расходу топлива
}

inline bool operator>(const Vehicle &l_TMP, const Vehicle &r_TMP) {
  return l_TMP._FUEL[2] >
         r_TMP._FUEL[2]; // Сравнение по смешанному расходу топлива
}

inline bool operator==(const Vehicle &_LTMP, const Vehicle &_RTMP) {
  return _LTMP._FUEL[2] ==
         _RTMP._FUEL[2]; // Сравнение по смешанному расходу топлива
}

#endif
