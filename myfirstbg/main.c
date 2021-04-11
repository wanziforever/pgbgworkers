#include "postgres.h"
#include "pgstat.h"
#include "postmaster/bgworker.h"
#include "storage/ipc.h"
#include "storage/latch.h"
#include "storage/proc.h"
#include "utils/elog.h"
#include "fmgr.h"


#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

int background_main(Datum main_arg) {
  ereport(LOG, (errmsg("---------------------------------------------------------------")));
  while (1) {
    ereport(LOG, (errmsg("ffffffffff")));
  }
  return 0;
}

void _PG_init(void) {
  BackgroundWorker worker;
  MemSet(&worker, 0, sizeof(BackgroundWorker));
	worker.bgw_flags = BGWORKER_SHMEM_ACCESS;
	worker.bgw_start_time = BgWorkerStart_RecoveryFinished;
	snprintf(worker.bgw_library_name, BGW_MAXLEN, "mytestbgworker");
	snprintf(worker.bgw_function_name, BGW_MAXLEN, "background_main");
	snprintf(worker.bgw_name, BGW_MAXLEN, "GoBackgroundWorker");
	worker.bgw_restart_time = BGW_NEVER_RESTART;
	worker.bgw_main_arg = (Datum) 0;
	worker.bgw_notify_pid = 0;
	RegisterBackgroundWorker(&worker);
}
