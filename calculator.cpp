#include "calculator.h"

Calculator::Calculator(QObject* inputTextArea, QObject* outputLabel) :
    _inputTextArea(inputTextArea), _outputLabel(outputLabel)
{
    QObject::connect(_inputTextArea,
                     SIGNAL(gotInput()),
                     this,
                     SLOT(calculate()));
}

void Calculator::calculate()
{
    // Get input from ui
    _expression = _inputTextArea->property("text").toString().toUtf8().constData();

    // Lex, parse and calculate


    // Write result to ui
    _result = QString::fromStdString(_expression);
    this->_outputLabel->setProperty("text", _result);
}
