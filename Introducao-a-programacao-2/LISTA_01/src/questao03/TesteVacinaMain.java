package questao03;

import java.time.LocalDate;

public class TesteVacinaMain {

	public static void main(String[] args) {
		//Testing enum
		LocaisEnum local1 = LocaisEnum.DRIVE_THRU_ARRUDA;
		LocaisEnum local2 = LocaisEnum.DRIVE_THRU_GERALDÃO;
		LocaisEnum local3 = LocaisEnum.CENTRO_DE_VACINAÇÃO_COMPAZ_ARIANO_SUASSUNA;
		LocaisEnum local4 = LocaisEnum.CENTRO_DE_VACINAÇÃO_PARQUE_DE_EXPOSIÇÃO;
		LocaisEnum local5 = LocaisEnum.DRIVE_THRU_PARQUE_DE_EXPOSIÇÃO;
		LocaisEnum local6 = LocaisEnum.DRIVE_THRU_UFRPE_UNIVERSIDADE_RURAL;
		
		//Setting people
		Pessoa[] pessoa = {
				new Pessoa("0333787383", "José Maria", LocalDate.of(1954, 3, 25)),
				new Pessoa("3830333787", "Maria José", LocalDate.of(1952, 6, 9)),
				new Pessoa("7870333383", "José Silva", LocalDate.of(1950, 8, 30)),
				new Pessoa("3787303383", "Maria Silva", LocalDate.of(1956, 1, 27)),
				new Pessoa("34575729094", "José Santos", LocalDate.of(1955, 12, 13)),
		};
		
		//Setting vaccine
		Vacina[] vacina = {
			new Vacina(6, "Coronavac", "132"),
			new Vacina(10, "Oxford", "174")
		};
		
		//Setting the register 
		RegistroVacina rv1 = new RegistroVacina();
		rv1.setVacinado(pessoa[0]);
		rv1.setDose(1);
		rv1.setId("479917759");
		rv1.setVacina(vacina[0]);
		rv1.setAtendente("Arnaldo Pereira da Silva");
		rv1.setGrupo("IDOSOS");
		rv1.setData_vacinacao(LocalDate.of(2021, 4, 22));
		rv1.setLocal(local1.name());
		
		RegistroVacina rv2 = new RegistroVacina();
		rv2.setVacinado(pessoa[1]);
		rv2.setDose(1);
		rv2.setId("417146255");
		rv2.setVacina(vacina[1]);
		rv2.setAtendente("Elisa Santana Correia");
		rv2.setGrupo("IDOSOS");
		rv2.setData_vacinacao(LocalDate.of(2021, 4, 25));
		rv2.setLocal(local2.name());
		
		RegistroVacina rv3 = new RegistroVacina();
		rv3.setVacinado(pessoa[2]);
		rv3.setDose(1);
		rv3.setId("456488029");
		rv3.setVacina(vacina[1]);
		rv3.setAtendente("Marluce Gonzaga de Araújo");
		rv3.setGrupo("OUTRAS PRIORIDADES");
		rv3.setData_vacinacao(LocalDate.of(2021, 4, 24));
		rv3.setLocal(local3.name());
		
		RegistroVacina rv4 = new RegistroVacina();
		rv4.setVacinado(pessoa[3]);
		rv4.setDose(1);
		rv4.setId("219965717");
		rv4.setVacina(vacina[0]);
		rv4.setAtendente("Geraldo Cristóvão Santos");
		rv4.setGrupo("IDOSOS");
		rv4.setData_vacinacao(LocalDate.of(2021, 4, 30));
		rv4.setLocal(local4.name());
		
		RegistroVacina rv5 = new RegistroVacina();
		rv5.setVacinado(pessoa[4]);
		rv5.setId("116437005");
		rv5.setVacina(vacina[1]);
		rv5.setAtendente("Marília Fernanda Albuquerque");
		rv5.setGrupo("TRABALHADORES DA SAÚDE");
		rv5.setData_vacinacao(LocalDate.of(2021, 4, 27));
		rv5.setLocal(local5.name());
		
		RegistroVacina rv6 = new RegistroVacina();
		rv6.setVacinado(pessoa[4]);
		rv6.setDose(2);
		rv6.setVacina(vacina[1]);
		rv6.setAtendente("Guilhermina Uberlândia dos Santos");
		rv6.setLocal(local6.name());
		
		//Adding to the list
		RelacaoVacinados rlv = new RelacaoVacinados();
		rlv.adicionar(rv1);
		rlv.adicionar(rv2);
		rlv.adicionar(rv3);
		rlv.adicionar(rv4);
		rlv.adicionar(rv5);
		rlv.adicionar(rv6);
		rlv.listarPessoasQueNaoTomaram2aDose();
		
	}
}
