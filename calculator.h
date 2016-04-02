#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDebug>
#include <string>

using namespace std;

/*!
 * \brief The Calculator class.
 * Read expression from ui, calculate and write result back to ui.
 */
class Calculator : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Instantiates a new Calculator object and binds the gotInput signal in inputTextArea
     * to the calculate slot.
     * \param inputTextArea The TextArea the user writes expressions into.
     * \param outputLabel   The Label that should display the result.
     */
    Calculator(QObject* inputTextArea, QObject* outputLabel);

public slots:
    /*!
     * \brief calculate
     * This slot reacts to the gotInput signal from the _inputTextArea object. It invokes a Lexer
     * and feeds the result to a Parser to obtain a result, that is written to the _outputLabel.
     */
    void calculate();

private:
    QObject* _inputTextArea;
    QObject* _outputLabel;
    string _expression;
    QString _result;
};

#endif // CALCULATOR_H
