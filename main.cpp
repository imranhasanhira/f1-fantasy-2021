#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve() {

}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int total_player, previous_games;
	cout << "Total player? ";
	cin >> total_player;
	cout << "Previous games? ";
	cin >> previous_games;

	std::vector<string> player_names(total_player + 1);
	std::vector<double> player_costs(total_player + 1), score_sum(total_player + 1);
	std::vector<std::vector<double>> player_scores(total_player + 1, std::vector<double>(previous_games, 0));
	for (int i = 1; i <= total_player; i++) {
		cout << "Enter the name & cost of " << i << "th player: ";
		cin >> player_names[i] >> player_costs[i];
		cout << "Now enter the previous scores: ";
		for (int j = 0; j < previous_games; j++) {
			cin >> player_scores[i][j];
			score_sum[i] += player_scores[i][j];
		}
	}
	int total_constructor;
	cin >> total_constructor;
	std::vector<string> constructor_names(total_constructor + 1);
	std::vector<double> constructor_costs(total_constructor + 1), score_sum_c(total_constructor + 1);
	std::vector<std::vector<double>> constructor_scores(total_constructor + 1, std::vector<double>(previous_games, 0));
	for (int i = 1; i <= total_constructor; i++) {
		cout << "Enter the name & cost of " << i << "th constructor: ";
		cin >> constructor_names[i] >> constructor_costs[i];
		cout << "Now enter the previous scores: ";
		for (int j = 0; j < previous_games; j++) {
			cin >> constructor_scores[i][j];
			score_sum_c[i] += constructor_scores[i][j];
		}
	}
	double max_budget;
	cout << "Enter your max budget: ";
	cin >> max_budget;
	std::vector<std::vector<ll>> potential_teams;
	std::vector<double> potential_team_cost, potential_team_score;
	std::vector<ll> your_team;

	double max_score_till_now = 0.0, min_cost_till_now = 1e18;
	for (int i = 1; i <= total_constructor; i++) {

		// selected constructor i
		// now have to select 5 players
		int number_of_players = 5;
		for (int j = 0; j < (1LL << total_player); j++) {
			std::vector<ll> team_idx;
			for (int k = 0; k < total_player; k++) {
				if ((1LL << k)&j) {
					team_idx.push_back(k + 1);
				}
			}
			if (team_idx.size() == number_of_players) {
				double total_cost = constructor_costs[i];
				double total_score = score_sum_c[i];
				for (int x : team_idx) {
					total_cost += player_costs[x];
					total_score += score_sum[x];
				}
				// adding constructor id at the end of the vector
				team_idx.push_back(i);
				if (total_cost <= max_budget) {
					potential_teams.push_back(team_idx);
					potential_team_cost.push_back(total_cost);
					potential_team_score.push_back(total_score);
					if (total_score > max_score_till_now) {
						max_score_till_now = total_score;
						min_cost_till_now = total_cost;
						your_team = team_idx;
					}
					else if (total_score == max_score_till_now && total_cost < min_cost_till_now) {

						max_score_till_now = total_score;
						min_cost_till_now = total_cost;
						your_team = team_idx;
					}
				}
			}
		}
	}
	cout << fixed << setprecision(3);

	cout << "Total spent: " << min_cost_till_now << endl;
	cout << "Total score: " << max_score_till_now << endl;

	cout << "Constructor name and cost: " << constructor_names[your_team.back()] << " " << constructor_costs[your_team.back()] << "\n";

	cout << "Players name and cost:\n";

	for (int i = 0; i < your_team.size() - 1; i++) {
		cout << player_names[your_team[i]] << " " << player_costs[your_team[i]] << endl;
	}
	cout << "Do you want to see other choices? Press Y or N: ";
	string key; cin >> key;
	if (key == "Y") {

		for (int i = 0; i < potential_teams.size(); i++) {
			your_team = potential_teams[i];
			cout << "Team " << i + 1 << ": ";
			cout << "Total spent: " << potential_team_cost[i] << endl;
			cout << "Total score: " << potential_team_score[i] << endl;

			cout << "Constructor name and cost: " << constructor_names[your_team.back()] << " " << constructor_costs[your_team.back()] << "\n";

			cout << "Players name and cost:\n";

			for (int i = 0; i < your_team.size() - 1; i++) {
				cout << player_names[your_team[i]] << " " << player_costs[your_team[i]] << endl;
			}
		}
	}
	cout << "End of the program!";
	return 0;
}
