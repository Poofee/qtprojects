#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum EntityStatusFlag {
        /** Flag for Undoables. */
        FlagUndone      = 1<<0,
        /** Entity Visibility. */
        FlagVisible     = 1<<1,
        /** Entity attribute (e.g. color) is defined by layer. */
        FlagByLayer     = 1<<2,
        /** Entity attribute (e.g. color) defined by block. */
        FlagByBlock     = 1<<3,
        /** Layer frozen. */
        FlagFrozen      = 1<<4,
        /** Layer frozen by default. */
        FlagDefFrozen   = 1<<5,
        /** Layer locked. */
        FlagLocked      = 1<<6,
        /** Used for invalid pens. */
        FlagInvalid     = 1<<7,
        /** Entity in current selection. */
        FlagSelected    = 1<<8,
        /** Polyline closed? */
        FlagClosed      = 1<<9,
        /** Flag for temporary entities (e.g. hatch) */
        FlagTemp        = 1<<10,
        /** Flag for processed entities (optcontour) */
        FlagProcessed   = 1<<11,
        /** Startpoint selected */
        FlagSelected1   = 1<<12,
        /** Endpoint selected */
        FlagSelected2   = 1<<13,
        /** Entity is highlighted temporarily (as a user action feedback) */
        FlagHighlighted = 1<<14
    };
    Q_DECLARE_FLAGS(EntityStatusFlags,EntityStatusFlag)

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setVisible();
    EntityStatusFlags status;
};
Q_DECLARE_OPERATORS_FOR_FLAGS(MainWindow::EntityStatusFlags)
#endif // MAINWINDOW_H
