using System;
using System.Globalization;

public class Example
{
	public static void Main()
	{
		string[] values = { "1,304.16", "$1,456.78", "1,094", "152",//an array af different strings to try and parse
							"123,45 €", "1 304,16", "Ae9f" };
		double number;
		CultureInfo culture = null;//Culture Info objects hold information concerning a different culture(time and date formats, etc)

		foreach(string value in values) {
			try {
				culture = CultureInfo.CreateSpecificCulture("en-US");//setting the way a string should be parsed to US english
				number = Double.Parse(value, culture);//attempt to  parse
				Console.WriteLine("{0}: {1} --> {2}", culture.Name, value, number);
			}
			catch (FormatException) {//THIS IS THE EXCEPTION YOU WANT TO USE
				Console.WriteLine("{0}: Unable to parse '{1}'.",
					culture.Name, value);
				culture = CultureInfo.CreateSpecificCulture("fr-FR");// try to parse in french
				try {
					number = Double.Parse(value, culture);
					Console.WriteLine("{0}: {1} --> {2}", culture.Name, value, number);
				}
				catch (FormatException) {
					Console.WriteLine("{0}: Unable to parse '{1}'.",
						culture.Name, value);
				}
			}
			Console.WriteLine();
		}
	}
}
// The example displays the following output:
//    en-US: 1,304.16 --> 1304.16
//    
//    en-US: Unable to parse '$1,456.78'.
//    fr-FR: Unable to parse '$1,456.78'.
//    
//    en-US: 1,094 --> 1094
//    
//    en-US: 152 --> 152
//    
//    en-US: Unable to parse '123,45 €'.
//    fr-FR: Unable to parse '123,45 €'.
//    
//    en-US: Unable to parse '1 304,16'.
//    fr-FR: 1 304,16 --> 1304.16
//    
//    en-US: Unable to parse 'Ae9f'.
//    fr-FR: Unable to parse 'Ae9f'.