#include "GameScene.h"

GameScene::GameScene(const int screenWidth, const int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

	HideCursor();

	Vector2 wall1Location = { 0, 0 };
	wall1.SetLocation(wall1Location);
	Vector2 wall1Dim = { screenWidth, WALL_HEIGHT };
	wall1.SetDim(wall1Dim);

	Vector2 wall2Dim = { screenWidth, WALL_HEIGHT };
	wall2.SetDim(wall2Dim);
	Vector2 wall2Location = { wall2.GetLocation().x, screenHeight - wall2.GetDim().y };
	wall2.SetLocation(wall2Location);

	p1.SetPlayerDirection(Direction::LEFT);
	p2.SetPlayerDirection(Direction::RIGHT);

	player1ScoreLabel.SetText(ConvertUIntToString(p1.GetScore()));
	player2ScoreLabel.SetText(ConvertUIntToString(p2.GetScore()));

	Vector2 score1Location = { 
		(screenWidth - player1ScoreLabel.GetTextDimensions().x) / 2 / 2, 
		SCORE1_Y
	};
	player1ScoreLabel.SetLocation(score1Location);
	Vector2 score2Location = { 
		(screenWidth - player2ScoreLabel.GetTextDimensions().x) / 2 + (score1Location.x),
		SCORE2_Y 
	};
	player2ScoreLabel.SetLocation(score2Location);

	ResetScene();
}

void GameScene::ResetScene() {
	Vector2 ballLocation = { (screenWidth / 2) - 40, (screenHeight - ball.GetDim().y) / 2 };
	ball.SetLocation(ballLocation);

	// player 1 location
	Vector2 p1Location = { (screenWidth / 2 - p1.GetDim().x) / 2, (screenHeight - p1.GetDim().y) / 2 };
	p1.SetLocation(p1Location);
	p1.SetBoundary(screenWidth, screenHeight - wall1.GetDim().y);

	// other player location
	Vector2 p2Location = { (screenWidth / 2 + screenWidth / 2 / 2), (screenHeight - p2.GetDim().y) / 2 };
	p2.SetLocation(p2Location);
	p2.SetBoundary(screenWidth*2, screenHeight - wall1.GetDim().y);
}

void GameScene::Render() {
	wall1.Draw();
	wall2.Draw();
	ball.Draw();
	p1.Draw();
	p2.Draw();
	player1ScoreLabel.Draw();
	player2ScoreLabel.Draw();
	Vector2 p1Speed = p1.GetSpeed();
	Player* curActivePlayer = &p1;

	if (IsKeyDown(KEY_UP)) {
		Vector2 newSpeed = {0, p1.GetConstantSpeed()*-1};
		curActivePlayer->SetSpeed(newSpeed);
		curActivePlayer->Move();
	}
	if (IsKeyDown(KEY_DOWN)) {
		Vector2 newSpeed = { 0, p1.GetConstantSpeed() };
		curActivePlayer->SetSpeed(newSpeed);
		curActivePlayer->Move();
	}
	if (IsKeyDown(KEY_LEFT)) {
		Vector2 newSpeed = { p1.GetConstantSpeed()*-1, 0};
		curActivePlayer->SetSpeed(newSpeed);
		curActivePlayer->Move();
	}
	if (IsKeyDown(KEY_RIGHT)) {                                             
		Vector2 newSpeed = { p1.GetConstantSpeed(), 0};
		curActivePlayer->SetSpeed(newSpeed);
		curActivePlayer->Move();
	}

	if (ball.IsCollidingWith(wall1) || ball.IsCollidingWith(wall2)) {
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { oldSpeed.x, oldSpeed.y * -1 };
		ball.SetSpeed(newSpeed);
	}

	if (ball.IsOutOfBoundaries(screenWidth)) {

		Vector2 ballLocation = ball.GetLocation();

		if (ballLocation.x < 0) {
			p2.IncreamentScore();
			player2ScoreLabel.SetText(ConvertUIntToString(p2.GetScore()));
		}
		else if((ballLocation.x + ball.GetDim().x) > screenWidth) {
			p1.IncreamentScore();
			player1ScoreLabel.SetText(ConvertUIntToString(p1.GetScore()));
		}

		ball.ResetLocation(screenWidth, screenHeight);
		ball.ToggleMoving();

		ResetScene();
	}

	ball.Move();

	if (ball.IsCollidingWith(*p1.GetParts()[0])) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { abs(BALL_SPEED), (oldSpeed.y > 0 ? oldSpeed.y*-1 : oldSpeed.y) };
		if (newSpeed.y == 0) {
			newSpeed.y = BALL_SPEED * -1;
		}
		ball.SetSpeed(newSpeed);
	}

	if (ball.IsCollidingWith(*p1.GetParts()[1])) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { abs(BALL_SPEED), oldSpeed.y*0 };

		ball.SetSpeed(newSpeed);
	}

	if (ball.IsCollidingWith(*p1.GetParts()[2])) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { abs(BALL_SPEED) , abs(oldSpeed.y)};
		if (newSpeed.y == 0) {
			newSpeed.y = BALL_SPEED * -1;
		}
		ball.SetSpeed(newSpeed);
	}

	// player 2 check
	if (ball.IsCollidingWith(*p2.GetParts()[0])) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { BALL_SPEED*-1, (oldSpeed.y > 0 ? oldSpeed.y * -1 : oldSpeed.y) };
		if (newSpeed.y == 0) {
			newSpeed.y = BALL_SPEED;
		}
		ball.SetSpeed(newSpeed);
	}

	if (ball.IsCollidingWith(*p2.GetParts()[1])) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { BALL_SPEED*-1, oldSpeed.y * 0 };

		ball.SetSpeed(newSpeed);
	}

	if (ball.IsCollidingWith(*p2.GetParts()[2])) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { BALL_SPEED*-1 , abs(oldSpeed.y) };
		if (newSpeed.y == 0) {
			newSpeed.y = BALL_SPEED;
		}
		ball.SetSpeed(newSpeed);
	}

	if (ball.IsMoving()) {
		Vector2 curSpeed = p2.GetSpeed();
		Vector2 newSpeed = { curSpeed.x, ball.GetSpeed().y + sin(ball.GetSpeed().y) };
		p2.SetSpeed(newSpeed);
		p2.Move();
	}
}