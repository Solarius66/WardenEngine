#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QActionGroup>
#include <QLabel>

#include "treeviewlayout.h"
#include "warden_lib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class InspectorElement;
class Inspector;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(const QString &path);

    protected:
    #ifndef QT_NO_CONTEXTMENU
        void contextMenuEvent(QContextMenuEvent *event) override;
    #endif // QT_NO_CONTEXTMENU
    //! [0]

    //! [1]
    private slots:
        void newFile();
        void open();
        void save();
        void print();
        void undo();
        void redo();
        void cut();
        void copy();
        void paste();
        void bold();
        void italic();
        void leftAlign();
        void rightAlign();
        void justify();
        void center();
        void setLineSpacing();
        void setParagraphSpacing();
        void about();
        void aboutQt();
        void mySelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    //! [1]

    //! [2]
    private:
        void createActions();
        void createMenus();
    //! [2]

    //! [3]
        QMenu *fileMenu;
        QMenu *editMenu;
        QMenu *formatMenu;
        QMenu *helpMenu;
        QActionGroup *alignmentGroup;
        QAction *newAct;
        QAction *openAct;
        QAction *saveAct;
        QAction *printAct;
        QAction *exitAct;
        QAction *undoAct;
        QAction *redoAct;
        QAction *cutAct;
        QAction *copyAct;
        QAction *pasteAct;
        QAction *boldAct;
        QAction *italicAct;
        QAction *leftAlignAct;
        QAction *rightAlignAct;
        QAction *justifyAct;
        QAction *centerAct;
        QAction *setLineSpacingAct;
        QAction *setParagraphSpacingAct;
        QAction *aboutAct;
        QAction *aboutQtAct;
        QLabel *infoLabel;

        QWidget *widget;
        QHBoxLayout *hLayout;
        TreeViewLayout *_TreeView;
        QVBoxLayout *_vLayoutExplorer;
        Inspector *_Inspector;
        QItemSelectionModel* _selectionModel;
    };
    //! [3]
#endif // MAINWINDOW_H
