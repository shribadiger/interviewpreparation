/*
  In a game, Coins are places in different locatons of 2D array,
  Positions of the coins are listed in vector. Now, If I place myself in
  2D Array. I should collect all the coins with shortest path. Implement the same
  example:
 + ----------------------+
 | . | . | O | . | . | . |
 + ----------------------+
 | . | . | . | . | O | . |
 + ----------------------+
 | O | . | . | . | . | . |
 + ----------------------+
 | . | . | Y | . | . | . |
 + ----------------------+
 | . | . | . | . | O | . |
 + ----------------------+
 | . | . | . | . | . | . |
 +-----------------------+
 Y -> your postions
 O -> coins placees
 */

#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
class Point {
	public:
		int x;
		int y;
		Point():x(0),y(0) {
		}

		Point(int xx, int yy):x(xx), y(yy) {
		}
		friend std::ostream& operator <<(std::ostream& os, Point& pt) {
			return os<<"["<<pt.x<<","<<pt.y<<"]";
		}
};

int getAbsoluteDistance(const Point& A, const Point& B)
{
	int result = abs(A.x - B.x)+abs(A.y - B.y);
	return result;
}

//checking the closest Points to You
Point& getClosestCoin(Point& yourPosition,
		      std:: vector<Point> coinPositions) {
	int shortestIndex = -1;
	int shortestDist = -1;
	for(unsigned int i=0; i<coinPositions.size(); i++) {
		int absDistance = getAbsoluteDistance(yourPosition, coinPositions[i]);
		if(shortestDist == -1 | absDistance < shortestDist) {
			shortestDist = absDistance;
			shortestIndex = i;
		}
	}
	return coinPositions[shortestIndex];
}


int main() {
	//Prpare data set
	std::cout<<"\n Test Case 1:\n";
	std::vector<Point> coinPositions;
	coinPositions.push_back(Point(2,0));
	coinPositions.push_back(Point(0,2));
	coinPositions.push_back(Point(1,4));
	coinPositions.push_back(Point(4,4));

	std::cout<<"\n Coins Postion List:\n";
	for(auto itr : coinPositions) {
		std::cout<<itr.x<<","<<itr.y<<"\n";
	}

	//Setting the Postion
	Point yourPosition = Point(3,2);

	int totalPoints = coinPositions.size();
	int totalLength = 0; 
	/*
	for(int i=0;i<totalPoints;i++) {
		std::cout<<(totalLength+=getAbsoluteDistance(yourPosition,coinPositions[i]))<<"\n";
	} */

	//Point closestCoin = getClosestCoin(yourPosition, coinPositions);
	//std::cout<<"\n Closest Coin Index: ["<<closestCoin.x<<","<<closestCoin.y<<"]\n";
	std::cout<<"Closest Coin : "<<getClosestCoin(yourPosition,coinPositions);

	std::cout<<"\n Test case 2: \n";
	coinPositions.clear();
	coinPositions.push_back(Point(3,3));
	coinPositions.push_back(Point(5,5));
	yourPosition = Point(1,1);
	std::cout<<"Closest Coin : "<<getClosestCoin(yourPosition,coinPositions);

	std::cout<<"\n Scenario -II :\n";
	/*
	 * Now, we have an opponent, He also want to get the coins. but before I need to grab my coins
	 * which is nearest to me. I assume that both me and opponent are moving same speed.
	 */
	//clear list before 
	coinPositions.clear();

	//Coin Locations.
	coinPositions.push_back(Point(2,0));
	coinPositions.push_back(Point(0,2));
	coinPositions.push_back(Point(1,4));
	coinPositions.push_back(Point(4,4));
	//Positions
	yourPosition = Point(3,2);
	Point opponentPosition = Point(3,4);

	int totalCoins = coinPositions.size();
	int *coinsForMe = new int[totalCoins];
	int *coinsForOpponent = new int[totalCoins];
	std::cout<<"\n Yours --- Opponent";
	for(int i=0;i<totalCoins;i++) {
		coinsForMe[i]=getAbsoluteDistance(yourPosition,coinPositions[i]);
		coinsForOpponent[i]=getAbsoluteDistance(opponentPosition,coinPositions[i]);
		std::cout<<"\n "<<coinsForMe[i]<<" --- "<<coinsForOpponent[i];
	}

	//Check which coin is nears to me
	Point myCoin;
	signed int closestValue=0;
	for(int i=0;i<totalCoins;i++) {
		signed int diffValue = coinsForMe[i]-coinsForOpponent[i];
		if(closestValue>diffValue){
			closestValue=diffValue;
			myCoin=coinPositions[i];
		}
	}

	std::cout<<"\n Closest coin for me  : "<<myCoin;


	return 0;
}

	

