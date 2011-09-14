#ifndef __ZLQTTREEDIALOG_H__
#define __ZLQTTREEDIALOG_H__

#include <QDialog>
#include <QListView>

#include <ZLTreeDialog.h>

#include "../tree/ZLQtTreeModel.h"
#include "../actions/LibraryActions.h"

class ZLQtTreeDialog : public QDialog, public ZLTreeDialog{
	Q_OBJECT;
public:
	ZLQtTreeDialog(QWidget* parent = 0);

public:
	void run();

public:
	void onNodeBeginInsert(ZLTreeNode *parent, size_t index);
	void onNodeEndInsert();
	void onNodeBeginRemove(ZLTreeNode *parent, size_t index);
	void onNodeEndRemove();
	void onNodeUpdated(ZLTreeNode *node);

public slots:
	void back();
	void enter(QModelIndex index);

private:
	QListView* myView;
	ZLQtTreeModel* myModel;

friend class ShowMenuLibraryAction; // for using protected rootNode() method
};

#endif /* __ZLQTTREEDIALOG_H__ */