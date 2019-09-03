//this snippet will cut up the sentence any time it sees the specified character (a space in this case)
string phrase = "The quick brown fox jumps over the lazy dog.";
string[] words = phrase.Split(' ');

foreach(var word in words)
{
	System.Console.WriteLine($"<{word}>");
}
// consecutive empty spaces will be save in the array as blank items
//to avoid this, use StringSplitOptions.RemoveEmptyEntries as a second parameter when using .Split

//you can create a list of delimiting characters to be split up the words
char[] delimiterChars = { ' ', ',', '.', ':', '\t' };

string text = "one\ttwo :,five six seven";
System.Console.WriteLine($"Original text: '{text}'");

string[] words = text.Split(delimiterChars);
System.Console.WriteLine($"{words.Length} words in text:");

foreach(var word in words)
{
	System.Console.WriteLine($"<{word}>");
}

//or a list of strings.
string[] separatingStrings = { "<<", "..." };

string text = "one<<two......three<four";
System.Console.WriteLine($"Original text: '{text}'");

string[] words = text.Split(separatingStrings, System.StringSplitOptions.RemoveEmptyEntries);
System.Console.WriteLine($"{words.Length} substrings in text:");

foreach(var word in words)
{
	System.Console.WriteLine(word);
}