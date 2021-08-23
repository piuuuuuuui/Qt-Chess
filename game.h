#pragma once
#include <vector>
#include <set>
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include "grid.h"

class Game : public QWidget {

  Q_OBJECT

public:
  Game(QWidget *parent = Q_NULLPTR);

protected:
  void paintEvent(QPaintEvent *);
  void mousePressEvent(QMouseEvent *);

private:
  // textures
  const std::vector<QPixmap> pics;
  // properties
  const std::vector<int> railwayStations;
  const std::vector<int> camps;
  const std::vector<std::set<int>> railways;
  // logic
  std::vector<std::vector<bool>> attackable;
  std::vector<std::vector<bool>> adjacent;
  // grids
  std::vector<Grid> grids;
  std::vector<STATUS> initStatus;
  // display
  QTransform rot;
  std::vector<QLabel *> pieces;
  // runtime variables
  bool available = false;
  int round;
  int focus;
  int numOfRM;
  int numOfBM;

  // initialize
  void setGrids();
  void setAdjacent();
  // other
  void setStatus(int, STATUS);
  void focusOn(int);
  void focusOff();
  void moveFromTo(int, int);
  void updateRound();
  bool isReachable(int, int);
  bool isAttackable(STATUS, STATUS);

public slots:
  void start();
  void win();
  void lose();

signals:
  void enableSurrender(bool);
  void over();
};