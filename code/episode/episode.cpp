	
	//scolped enum
	int main(){
		enum class stoplight{red, green,yellow	};

		stoplight l = stoplight::red;
		switch (l){
		case stoplight::red:
			cout << "stop!" << endl;
			break;
		case stoplight::green:
			cout << "pass carefully" << endl;
			break;
		case stoplight::yellow:
			cout << "slow down" << endl;
			break;
		default:
			cout << "light broken, call 122" << endl;
			break;
		}
	}