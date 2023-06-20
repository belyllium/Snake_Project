#include <ncurses.h> 
#include <queue> 
#include <utility> 
using namespace std;

#ifndef __SNAKEGAME_H_
#define __SNAKEGAME_H_

struct point{
	int x;
	int y;
};

class SnakeGame
{
private:
	/* 맵 변수 */
	int row=0, col=0;

	/* 뱀 변수 */
	queue<pair<int,int> > xy; // 뱀 위치를 저장하기 위한 큐
point head; // 머리의 x, y 좌표
point body; // 몸통의 x, y 좌표
point tail; // 꼬리의 x, y 좌표
int max_length; // 뱀의 최대 길이
int length=3; // 뱀의 길이 (게임 시작 시 뱀의 길이는 3)
char direction; // 뱀의 방향

/* 점수판 매개변수 */
int score; // 게임의 점수
int tick; // 시간 지연 체크
int height, width;
int vertical , horizontal; // 터미널의 길이
int Randheight, Randwidth; // 뱀 머리의 위치
int ch; // 키보드
point start; // 시작점의 x, y 좌표
int count1=0,count2=0,count3=0,count4=0; // 성장 아이템(count1), 독(count2) 아이템, 게이트(count3), 함정(count4)에 대한 시간 카운트
int num_gate=0; // 뱀이 통과한 게이트 수

/* 벽 매개변수 */
int wall[21][42]={0,}; // 벽->1, 벽이 아님->0
int wallCopy[21][42]={0,};

/* 게이트 매개변수 */
point gate1; // 게이트1의 x, y 좌표
point gate2; // 게이트2의 x, y 좌표
point in; // 입구의 x, y 좌표
point out; // 출구의 x, y 좌표

/* 성장 아이템 매개변수 */
point growth; // 성장 아이템의 x, y 좌표
int num_growth=0; // 성장 아이템의 개수

/* 독 아이템 매개변수 */
point poison; // 독 아이템의 x, y 좌표
int num_poison=0; // 독 아이템의 개수

/* 함정 매개변수 */
point Trap; // 함정의 x, y 좌표

/* 미션 매개변수 */
int mission_length; // 뱀의 미션 길이
int mission_growth; // 성장 아이템의 미션 개수
int mission_poison; // 독 아이템의 미션 개수
int mission_gate; // 게이트의 미션 개수


///* 메소드 *///
void StartWindow(); // 윈도우 초기화

/* 뱀 함수 */
void LocateSnake(); // 뱀을 맵에 배치
void WrongDirection(); // 뱀이 잘못된 방향으로 움직일 경우, 게임 오버
void BumpedintoBody(); // 뱀 머리가 몸통에 부딪혔는지 확인
void SizeofSnake(); // 뱀의 길이가 3보다 작은지 확인
int ControlSnake(); // 입력 받기 + tick에 따른 이동
bool IsBody(int,int); // 뱀 머리가 몸통에 부딪혔는지 확인

/* 맵 함수 */
void MakeMap1(); // 맵1 만들기

/* 벽 함수 */
void BumpedintoWall(); // 뱀이 벽에 부딪혔는지 확인

/* 성장 아이템 함수 */
void RandGrowthItem(); // 성장 아이템(5)을 맵에 무작위로 배치
bool EatGrowthItem(); // 뱀이 성장 아이템을 먹었는지 확인

/* 독 아이템 함수 */
void RandPoisonItem(); // 독 아이템(6)을 맵에 무작위로 배치
bool EatPoisonItem(); // 뱀이 독 아이템을 먹었는지 확인

/* 함정 함수 */
void RandTrap(); // 함정(@)을 맵에 무작위로 배치
void BumpedintoTrap(); // 뱀이 함정에 부딪혔는지 확인
bool IsTrap(); // 뱀이 함정에 빠졌는지 확인

/* 게이트 함수 */
void RandGate(); // 게이트(0)을 맵에 무작위로 배치
void ControlGate(); // 게이트 사용 규칙
bool IsGate(); // 뱀 머리가 게이트에 부딪혔는지 확인
bool IsEdgeGate(); // 게이트가 가장자리에 있는지 확인

/* 점수판 함수 */
void ScoreBoard(); // 점수판

/* 미션 함수 */
bool CheckMission(); // 플레이어가 미션을 완료했는지 확인



public:
	SnakeGame(); // 생성자
	~SnakeGame(); // 소멸자
	void Start(int); // 게임시작
	bool death = false; // 죽었는 지 확인
	bool GameStart = false; // 게임 시작 여부
    int stage=1; // 스테이지 변수
};

#endif