#ifndef DICEPARSER_H
#define DICEPARSER_H

#include <QString>
#include <QMap>

#include "node/executionnode.h"
#include "node/dicerollernode.h"

#include "validator.h"
#include "range.h"
#include "booleancondition.h"

/**
 * @mainpage DiceParser
 *
 * the grammar is something like this:
 *
 * Command =: Expression | ScalarOperator Expression
 * Expression =: number | number Dice | Command
 * Dice =: DiceOperator Number(faces)
 * DiceOperator =: D
 * ScalarOperator =: [x,-,*,x,/]
 * number =: [0-9]+
 *
 */

class Dice;
/**
 * @brief The DiceParser class facade class, it receives a command and return a DiceResult class (not yet implemented).
 */
class DiceParser
{

public:
    /**
     * @brief The DiceOperator enum gathering all dice operators
     */
    enum DiceOperator {D};



    /**
     * @brief The OptionOperator enum gathering all options  availables for result.
     */
    enum OptionOperator {KeepAndExplose,keep,Reroll,Explosing,Sort,Count};

    /**
     * @brief DiceParser default constructor
     */
    DiceParser();

    /**
     * @brief parseLine, method to call for starting the dice roll. It will parse the command and run the execution tree.
     * @param str dice command
     * @return bool every thing is fine or not
     */
    bool parseLine(QString str);


    /**
     * @brief Start running the execution tree
     *
     */
    void Start();

    /**
     * @brief displayResult
     */
    void displayResult();

private:
    /**
     * @brief readNumber read number in the given str and remove from the string the read character.
     * @param str the command line
     * @param myNumber reference to the found number
     * @return true, succeed to read number, false otherwise.
     */
    bool readNumber(QString&  str, int& myNumber);
    /**
     * @brief readDice
     * @param str
     * @return
     */
    bool readDice(QString&  str,Dice&);
    /**
     * @brief readDiceOperator
     * @return
     */
    bool readDiceOperator(QString&,DiceOperator&);
    /**
     * @brief readDiceExpression
     * @param node
     * @return
     */
    bool readDiceExpression(QString&,ExecutionNode*  & node);
    /**
     * @brief readOperator
     * @return
     */
    bool readOperator(QString&,ExecutionNode* previous);
    /**
     * @brief setCurrentNode
     * @param node
     */
    void setCurrentNode(ExecutionNode* node);

    /**
     * @brief readOption
     */
    bool readOption(QString&,ExecutionNode* node, DiceRollerNode* diceNode);

    /**
     * @brief addSort
     * @param b
     */
    ExecutionNode* addSort(ExecutionNode*, bool b);

    /**
     * @brief readValidator
     * @param str
     * @param validator
     * @return
     */
    Validator* readValidator(QString& str);


    bool readLogicOperator(QString& str,BooleanCondition::LogicOperator& condition);



private:
    QMap<QString,DiceOperator>* m_mapDiceOp;
    QMap<QString,OptionOperator>* m_OptionOp;
    QMap<QString,BooleanCondition::LogicOperator>* m_logicOp;
    ExecutionNode* m_start;
    ExecutionNode* m_current;
    QString m_command;
};

/**
 * @brief The Dice class is a basic class to store dice. (May not be required any more).
 */
class Dice
{
public:
   DiceParser::DiceOperator m_diceOp;
   int m_faces;
};

#endif // DICEPARSER_H
