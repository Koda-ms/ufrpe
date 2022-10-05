package questao02;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Tempo {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		//Letter A - Converting String to date
		System.out.println("Entre com uma data no formato 'ddmmaaaa' (sem barras): ");
		String dataRecebida = scan.nextLine();
		
		DateTimeFormatter parserData = DateTimeFormatter.ofPattern("ddMMuuuu");
		LocalDate data = LocalDate.parse(dataRecebida, parserData);
		DateTimeFormatter formatarData = DateTimeFormatter.ofPattern("dd/MM/uuuu");
		formatarData.format(data);
		
		//Letter B - Calculating the difference between two dates
		LocalDate hoje = LocalDate.now();
		Period periodo = Period.between(data, hoje);
		System.out.printf("Diferença de %s dias entre as datas", periodo.getDays());
		
		//Letter C - Adding days to the one typed by user
		LocalDate diasAFrente = data.plusDays(110);
		
		//Letter D - Changing the date's month to August
		LocalDate mudarMes = data.withMonth(8);
		
		//Letter E - Printing the altered date formatted
		DateTimeFormatter formatarDataAlterada = DateTimeFormatter.ofPattern("dd/MM/uuuu");
		String dataAlteradaFormatada = formatarDataAlterada.format(mudarMes);
		System.out.println("\nA data alterada fica: " + dataAlteradaFormatada);
		
		System.out.println();
		
		//Letter F - Calculating the quantity of working days between two dates
		System.out.println("Entre com duas data, no formato 'ddmmaaaa' (sem barras), para calcular a quantidade de dias entre elas ");
		
		System.out.println("Primeira data: ");
		String data1 = scan.nextLine();
		System.out.println("Segunda data: ");
		String data2 = scan.nextLine();
		
		System.out.println("Há " + quantidadeDiasUteis(data1, data2) + " dias úteis nesse intervalo.");
	}
	
	public static int quantidadeDiasUteis(String data1, String data2) {
		
		//Converting the date from String to LocalDate
		DateTimeFormatter parserData1 = DateTimeFormatter.ofPattern("ddMMuuuu");
		LocalDate primeiraData = LocalDate.parse(data1, parserData1);
		DateTimeFormatter formatarData1 = DateTimeFormatter.ofPattern("dd/MM/uuuu");
		formatarData1.format(primeiraData);
		
		DateTimeFormatter parserData2 = DateTimeFormatter.ofPattern("ddMMuuuu");
		LocalDate segundaData = LocalDate.parse(data2, parserData2);
		DateTimeFormatter formatarData2 = DateTimeFormatter.ofPattern("dd/MM/uuuu");
		formatarData2.format(segundaData);
		
		//Calculating the days between the dates
		Period dias = Period.between(primeiraData, segundaData);
		int quantidadeDias = dias.getDays();
		
		//Removing the weekend
		int somaDiasUteis = 0;
		for(int dia = 0; dia <= quantidadeDias; dia++) {
			 if(primeiraData.plusDays(dia).getDayOfWeek() != DayOfWeek.SATURDAY && 
					 primeiraData.plusDays(dia).getDayOfWeek() != DayOfWeek.SUNDAY) {
				 somaDiasUteis++; 
			 }
		}
		return somaDiasUteis;
	}
}
