# Formula1 Fantasy Race Prediction

Playing with AI to predict Formula 1 race results

## Motivation

The main motivation came into while playing [Formula 1 fantasy league](https://fantasy.formula1.com). In the game, a player has a budget (initial 100 million USD ) and he has to manage a team of one constructor and five drivers within that budget. The price of the drivers changes realtime based on formula 1 racing results going for the whole season. Detail game rules can be found on [official formula fantasy page](https://fantasy.formula1.com/game-rules)



## Our target

Looking at most of the recent races, we think that there could be a relation of `Main race` result with the results from `Qualifying race` and `Free practice` result. `Qualifying race` has the most relevance contribution to main race result. `Free practice` races has least contribution since teams do all kind of technical tests, including [sandbagging](https://en.wikipedia.org/wiki/Sandbagging) effect.

There are other factors that we can look into. For example, performance of a driver on the same racing circuit, could be a good feature. Or previous performances of a driver on a `similar` circuit. A drivers recent race performance could also be a good indicator of his current form.

Considering all these assumptions, we will try to validate our idea via machine learning model. We need to come up with set of feature list and train a AI model with previous race data. Previous race results can be found in this kaggle [Formula 1 World Championship (1950 - 2021)](https://www.kaggle.com/rohanrao/formula-1-world-championship-1950-2020)
