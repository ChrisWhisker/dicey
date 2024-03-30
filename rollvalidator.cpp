#include "rollvalidator.h"

RollValidator::State RollValidator::validate(QString &input, int &pos) const
{
    static QRegularExpression rx("^(?!.*[Dd][Dd])[0-9dD+\\-*/]*$"); // Regular expression to allow digits and specified math operators
    if (rx.match(input).hasMatch() || input.isEmpty()) {
        return Acceptable; // Accept if the input matches the regular expression or is empty
    } else {
        return Invalid; // Reject otherwise
    }
}
