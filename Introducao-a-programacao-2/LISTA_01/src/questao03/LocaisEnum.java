package questao03;

public enum LocaisEnum {
	
		DRIVE_THRU_UFRPE_UNIVERSIDADE_RURAL("Drive Thru - UFRPE - Universidade Federal de Pernambuco"),
		DRIVE_THRU_GERALD�O("Drive Thru Gerald�o"),
		CENTRO_DE_VACINA��O_PARQUE_DE_EXPOSI��O("Centro de Vacina��o Parque de Exposi��o"),
		CENTRO_DE_VACINA��O_COMPAZ_ARIANO_SUASSUNA("Centro de Vacina��o Compaz Ariano Suassuna"),
		DRIVE_THRU_PARQUE_DE_EXPOSI��O("Drive Thru Parque de Exposi��o"),
		DRIVE_THRU_ARRUDA("Drive Thru Arruda");
		
		private String local;
		
		LocaisEnum(String local) {
			this.local = local;
		}
		public String getLocal() {
			return this.local;
		}

}
