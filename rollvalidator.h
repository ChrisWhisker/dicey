#ifndef ROLLVALIDATOR_H
#define ROLLVALIDATOR_H

#include <QApplication>
#include <QLineEdit>
#include <QValidator>
#include <QRegularExpression>

class RollValidator : public QValidator
{
public:
    RollValidator(QObject *parent = nullptr) : QValidator(parent) {};

    // Validate the input
    State validate(QString &input, int &pos) const override;
};

#endif // ROLLVALIDATOR_H
