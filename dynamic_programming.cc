/*
 * dynamic_programming.cc
 *
 *  Created on: May 4, 2016
 *      Author: anshul
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>

#include <unordered_set>

using namespace std;

/*!
 * https://www.careercup.com/question?id=5359122669109248
 *
 * Given an input string and a dictionary of words, find out if the input string
 * can be segmented into a space-separated sequence of dictionary words.
 *  You need to output the minimum number of words. For example, input: "aaaisaname"
dict: ("a", "aaa", "is", "name")

output: "aaa is a name"

Wrong output: "a a a is a name"
 */
void
words_min_cut() {

	unordered_set<string> dict;

	dict.insert("a");
	dict.insert("aaa");
	dict.insert("is");
	dict.insert("name");
	dict.insert("namey");
	dict.insert("y");

	string s("aaaisanamey");

	int min_num_words_ending_at[s.length()];
	vector<vector<string> > min_words_ending_at;
	min_words_ending_at.resize(s.length());

	for (int i = 0;i < s.length();++i) {

		min_num_words_ending_at[i] = i + 1;
		string min_word;
		int min_j = 0;
		for (int j = i;j >= 0;--j) {
			string current = s.substr(j, i - j + 1);

			if (dict.find(current) != dict.end()) {
				int min_at_pos = j > 0 ? min_num_words_ending_at[j - 1] + 1 : 1;

				if (min_at_pos < min_num_words_ending_at[i]) {
					min_num_words_ending_at[i] = min_at_pos;
					min_word = current;
					min_j = j > 0 ? j - 1 : 0;
				}
			}
		}

		//min_words_ending_at.at(i).resize(i);

		min_words_ending_at.at(i).insert(min_words_ending_at.at(i).begin(), min_words_ending_at.at(min_j).begin(),
				min_words_ending_at.at(min_j).end());

		min_words_ending_at.at(i).push_back(min_word);
	}

	cout << "min cut words: " << min_num_words_ending_at[s.length() - 1] << endl;

	vector<string> last = min_words_ending_at[s.length() - 1];

	for (int i = 0;i < last.size();++i) {
		cout << last.at(i) << endl;
	}

}

/*!
 * Given a matrix of dimensions mxn having all entries as 1 or 0,
 * find out the size of maximum size square sub-matrix with all 1s.
 */
void
largest_square_matrix() {
	const int x = 5;
	const int y = 4;
	int a[][y] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 0}};

	int number_of_1s_left[x][y];
	memset(number_of_1s_left, 0, sizeof(int) * x * y);

	int number_of_1s_top[x][y];
	memset(number_of_1s_top, 0, sizeof(int) * x * y);

	int square_matrix_ending_at[x][y];
	memset(square_matrix_ending_at, 0, sizeof(int) * x * y);

	for (int i = 0;i < x;++i) {
		for (int j = 0;j < y;j++) {
				square_matrix_ending_at[i][j] = a[i][j];
		}
	}

	int max_sq_mat_size = 0;
	for (int i = 1;i < x;++i) {
		for (int j = 1;j < y;++j) {
			number_of_1s_left[i][j] = a[i][j - 1] == 1 ? number_of_1s_left[i][j - 1] + 1 : 0;
			number_of_1s_top[i][j] = a[i - 1][j] == 1 ? number_of_1s_top[i - 1][j] + 1 : 0;

			if (a[i][j] == 1) {
				int pre_sq_mat_size = square_matrix_ending_at[i - 1][j - 1];
				if (pre_sq_mat_size <= number_of_1s_left[i][j] && pre_sq_mat_size <= number_of_1s_top[i][j]) {
					square_matrix_ending_at[i][j] = pre_sq_mat_size + 1;

					if (square_matrix_ending_at[i][j] > max_sq_mat_size)
						max_sq_mat_size = square_matrix_ending_at[i][j];

				}
			}
		}
	}

	cout << max_sq_mat_size << endl;
}

void
subset_sum(int *a, int size) {
	for (int i = 0;i < size;++i) {

	}
}

void
shortest_palindrome() {

}

bool
max_As() {

}

int
main() {
	largest_square_matrix();

	int a[] = {5, 2, 4, 7, 9, 1};
	subset_sum(a);
}
