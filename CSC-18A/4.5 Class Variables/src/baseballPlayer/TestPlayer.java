//pg.209 Using static fields
package baseballPlayer;

public class TestPlayer {
	public static void main(String[] args) {
		BaseballPlayer aCather = new BaseballPlayer(12, .218);
		BaseballPlayer aShortstop = new BaseballPlayer(31, .385);
		aCather.showPlayer();
		aShortstop.showPlayer();
		BaseballPlayer anOutfielder = new BaseballPlayer(44, .505);
		anOutfielder.showPlayer();
		aCather.showPlayer();
	}
}
