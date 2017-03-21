#ifndef POPULATIONSQUARE_HPP
#define POPULATIONSQUARE_HPP

class PopulationSquare {
  private:
    enum SquareType { any, money, research, production, orbital };
    SquareType square;
    bool advanced;
    bool populated;

  public:
    PopulationSquare(SquareType square, bool advanced);
    ~PopulationSquare();
};

#endif
