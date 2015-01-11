// Very crude very slow but simple BigInteger implementation
// Takes a string and turns it into a doubly-linked list of ints
// Only handles positive addition
// Crappy but decent none the less

class BigInt {
public:
  BigInt(string str) {
		for (auto s : str) {
			string singleString{ s };
			data.push_back(stoi(singleString));
		}
	}

	BigInt() {
		data = { 0 };
	}

	void print() {
		for (auto d : data) {
			cout << d;
		}
	}

	string to_string() {
		string dataString;
		dataString.reserve(data.size());

		for (auto d : data) {
			dataString.append(std::to_string(d));
		}

		return dataString;
	}

	size_t size() {
		return data.size();
	}

	BigInt plus(BigInt other) {
		list<int> newList = { 0 };
		auto newListIter = newList.rbegin();

		auto iter = data.rbegin();
		auto otherIter = other.data.rbegin();

		while (iter != data.rend() && otherIter != other.data.rend()) {
			*newListIter += *iter + *otherIter;

			if (*newListIter >= 10) {
				newList.push_front(1);
				*newListIter -= 10;
			}

			++iter;
			++otherIter;

			if (iter == data.rend() && otherIter != other.data.rend()) {
				data.push_front(0);
			}

			if (iter != data.rend() && otherIter == other.data.rend()) {
				other.data.push_front(0);
			}

			if (iter == data.rend() && otherIter == other.data.rend()) {
				break;
			}

			if (++newListIter == newList.rend()) {
				newList.push_front(0);
			}
		}

		return BigInt(dataToString(newList));
	}

private:
  string dataToString(list<int> dataList) {
		string dataString;
		dataString.reserve(dataList.size());

		for (auto d : dataList) {
			dataString.append(std::to_string(d));
		}

		return dataString;
	}

	list<int> data;
};
