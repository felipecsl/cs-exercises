var SetBitCounter = function() {
	this.count = function(number) {
		var total = 0;

		while(number > 0) {
			if((number & 1) == 1)
				total++;

			number = number >>> 1;
		}

		return total;
	};
};