/**
 * \file Value.h
 */

#ifndef Value_h
#define Value_h

enum class ValueType {Force, Intelligence, Luck, Agility, Wisdom, Life};

class Value {
  private:
  protected:
  public:
    int val;
    ValueType type;

  public:
    Value(const int& value, const ValueType& type): val(value), type(type)
    {
    }
    // Public methods


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // Value_h
