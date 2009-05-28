assert = function(val){
    AssertionError = function(string){
	this.name = "AssertionError"
	this.message = string;
    }

    if (!val)
	throw new AssertionError("Assertion failed");
}
