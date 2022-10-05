package questao03;

public enum LocaisEnum {
	
		DRIVE_THRU_UFRPE_UNIVERSIDADE_RURAL("Drive Thru - UFRPE - Universidade Federal de Pernambuco"),
		DRIVE_THRU_GERALDÃO("Drive Thru Geraldão"),
		CENTRO_DE_VACINAÇÃO_PARQUE_DE_EXPOSIÇÃO("Centro de Vacinação Parque de Exposição"),
		CENTRO_DE_VACINAÇÃO_COMPAZ_ARIANO_SUASSUNA("Centro de Vacinação Compaz Ariano Suassuna"),
		DRIVE_THRU_PARQUE_DE_EXPOSIÇÃO("Drive Thru Parque de Exposição"),
		DRIVE_THRU_ARRUDA("Drive Thru Arruda");
		
		private String local;
		
		LocaisEnum(String local) {
			this.local = local;
		}
		public String getLocal() {
			return this.local;
		}

}
